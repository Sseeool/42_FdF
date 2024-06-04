#include "minilibx-linux/mlx.h"
#include "fdf.h"
#include "get_next_line/get_next_line.h"
#include <stdio.h>
#include "libft/libft.h"

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
	int		size;

    check_argc(argc);
    struct1 = read_map(argv[1], &size);
    isometric(struct1, size);
    window.mlx_ptr = mlx_init();
    window.win_ptr = mlx_new_window(window.mlx_ptr, 1280, 960, "My Window");
    image.img = mlx_new_image(window.mlx_ptr, 1280, 960);
    image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel, &image.line_length, &image.endian);
    draw(struct1, size, &image);
    // mlx_key_hook(win_ptr, deal_key, (void *)0);
    //mlx_put_image_to_window(mlx_ptr, win_ptr, image.img, 0, 0);
    mlx_loop(window.mlx_ptr);

    return 0;
}