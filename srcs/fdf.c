/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 00:20:12 by eonoh             #+#    #+#             */
/*   Updated: 2024/06/29 20:13:31 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	set_window(t_window *window, t_data *image)
{
	window->mlx_ptr = mlx_init();
	window->win_ptr = \
	mlx_new_window(window->mlx_ptr, WIDTH, HEIGHT, "FdF");
	image->img = mlx_new_image(window->mlx_ptr, WIDTH, HEIGHT);
	image->addr = mlx_get_data_addr(image->img, &(image)->bits_per_pixel, \
				&(image)->line_length, &(image)->endian);
	window->data = image;
}

void	set_map(char *argv, t_map *fdf)
{
	int	i;

	i = 0;
	fdf->size = get_map_size(argv, fdf);
	fdf->map = (t_pos *)malloc(sizeof(t_pos) * (fdf->size + 1));
	if (!(fdf->map))
		error_message("Failed to allocate map.\n");
	fdf->i_map = (t_pos *)malloc(sizeof(t_pos) * (fdf->size + 1));
	if (!(fdf->i_map))
		error_message("Failed to allocate i_map.\n");
	fdf->int_map = (t_ipos *)malloc(sizeof(t_pos) * (fdf->size + 1));
	if (!(fdf->int_map))
		error_message("Failed to allocate int_map.\n");
	fdf->x_angle = 30;
	fdf->y_angle = 30;
	read_map(argv, fdf);
	put_center(fdf, fdf->map, i);
	put_center(fdf, fdf->i_map, i);
	set_mapdup(fdf);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	main(int argc, char **argv)
{
	t_window	window;
	t_data		image;
	t_map		fdf;

	if (argc != 2)
		error_message("FDF program expects 2 arguments.\n");
	is_valid_arg(argv[1]);
	set_map(argv[1], &fdf);
	set_window(&window, &image);
	draw_line(&fdf, &image);
	mlx_put_image_to_window(window.mlx_ptr, window.win_ptr, image.img, 0, 0);
	mlx_key_hook(window.win_ptr, key_press, &window);
	mlx_hook(window.win_ptr, 17, 0, mlx_close, &window);
	mlx_loop(window.mlx_ptr);
	return (0);
}
