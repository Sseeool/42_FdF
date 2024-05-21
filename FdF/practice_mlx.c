#include "minilibx-linux/mlx.h"
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
    //void    *mlx_ptr;
    //void    *win_ptr;
    char    **maps;
    int     fd;
    int     i;
    //t_data  image;

    if (!(argc == 2))
        return (0);
    i = 0;
    fd = open(argv[1], O_RDONLY);
    while (1)
    {
        maps[i] = get_next_line(fd);
        if (maps[i] == NULL)
            break;
        printf("%s", maps[i]);
        i++;
    }
    close(fd);

    /*mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, 500, 500, "My Window");
    image.img = mlx_new_image(mlx_ptr, 500, 500);
    image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel, &image.line_length, &image.endian);
    mlx_pixel_put(mlx_ptr, win_ptr, 250, 250, 0x00FF00);
    // mlx_key_hook(win_ptr, deal_key, (void *)0);
    //mlx_put_image_to_window(mlx_ptr, win_ptr, image.img, 0, 0);
    mlx_loop(mlx_ptr);*/

    return 0;
}