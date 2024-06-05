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

int main(int argc, char **argv)
{
    //line_data   *map;
    window_data window;
    t_data  image;
	line_data	*struct1;
	int		y;
	int		x;

	y= 0;
    check_argc(argc);
    struct1 = read_map(argv[1], &y);
    //isometric(struct1, x * y);
	x = get_x_size(struct1);
    window.mlx_ptr = mlx_init();
    window.win_ptr = mlx_new_window(window.mlx_ptr, 1920, 1080, "My Window");
    image.img = mlx_new_image(window.mlx_ptr, 1920, 1080);
    image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel, &image.line_length, &image.endian);
    //draw(struct1, x * y, &image);
	printf("###%d\n", struct1[x - 1].x);
	draw_line(struct1, x, y, &image);
    // mlx_key_hook(win_ptr, deal_key, (void *)0);
    mlx_put_image_to_window(window.mlx_ptr, window.win_ptr, image.img, 0, 0);
    mlx_loop(window.mlx_ptr);

    return 0;
}