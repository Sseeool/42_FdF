#include "fdf.h"

/*void ft_putchar(char c)
{
    write(1, &c, 1);
}

int deal_key()
{
    ft_putchar('x');
    return 0;
}*/

line_data	*duplicate_map(line_data *map_pos, int size)
{
	line_data	*dup;
	int			i;

	dup = (line_data *)malloc(sizeof(line_data) * (size + 1));
	if (!dup)
	{
		perror("Failed to allocate duplicated map_pos");
		exit(1);
	}
	i = 0;
	while (i < size)
	{
		dup[i] = map_pos[i];
		i++;
	}
	dup[i].color = -1;
	return (dup);
}

void	setting_window(window_data *window, t_data *image)
{
	window->mlx_ptr = mlx_init();
	window->win_ptr = mlx_new_window(window->mlx_ptr, WIDTH, HEIGHT, "My Window");
	image->img = mlx_new_image(window->mlx_ptr, WIDTH, HEIGHT);
	image->addr = mlx_get_data_addr(image->img, &(image)->bits_per_pixel, &(image)->line_length, &(image)->endian);
}

line_data	*set_map_info(char *argv, int *size)
{
	line_data	*map_pos;
	line_data	*map_dup;
	map_range	pos_range;
	map_range	isometric_range;
	int			y;

	y = 0;
	*size = get_map_size(argv);
	map_pos = read_map(argv, &y, *size, &pos_range);
	// duplicate map for top view
	map_dup = duplicate_map(map_pos, *size);
	isometric(map_pos, *size, &isometric_range);
	center_coordinates(map_pos, isometric_range, *size, y);
	// 나중에 top_view의 scale 도 구해주기
	//scale = get_scale(isometric_range);
	return (map_pos);
}

int main(int argc, char **argv)
{
    window_data window;
    t_data  image;
	line_data	*map_pos;
	//line_data	*map_dup;
	//map_range	pos_range;
	//int		y;
	int     size;
	// x = size / y

	//y= 0;
	check_argc(argc);
	setting_window(&window, &image);
	map_pos = set_map_info(argv[1], &size);
	//size = get_map_size(argv[1]);
	//map_pos = read_map(argv[1], &y, size, &pos_range);
	//if (!map_pos)
	//	return 1;
	//// duplicate map for top view
	//map_dup = duplicate_map(map_pos, size);
	//isometric(map_pos, size);
	draw(map_pos, size, &image);
	// printf("###%d\n", struct1[x - 1].x);
	// //draw_line(struct1, x, y, &image);
    // // mlx_key_hook(win_ptr, deal_key, (void *)0);
	mlx_put_image_to_window(window.mlx_ptr, window.win_ptr, image.img, 0, 0);
	mlx_loop(window.mlx_ptr);

	return 0;
}