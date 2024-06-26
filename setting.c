/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 20:08:21 by eonoh             #+#    #+#             */
/*   Updated: 2024/06/26 23:01:45 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_window(t_window *window, t_data *image)
{
	window->mlx_ptr = mlx_init();
	window->win_ptr = mlx_new_window(window->mlx_ptr, WIDTH, HEIGHT, "My Window");
	image->img = mlx_new_image(window->mlx_ptr, WIDTH, HEIGHT);
	image->addr = mlx_get_data_addr(image->img, &(image)->bits_per_pixel, &(image)->line_length, &(image)->endian);
}

void	set_map(char *argv, t_map *fdf)
{
	int	i;

	i = 0;
	fdf->size = get_map_size(argv, fdf);
	fdf->map = (t_pos *)malloc(sizeof(t_pos) * (fdf->size + 1));
	allocate_error(fdf->map);
	fdf->i_map = (t_pos *)malloc(sizeof(t_pos) * (fdf->size + 1));
	allocate_error(fdf->i_map);
	fdf->int_map = (t_ipos *)malloc(sizeof(t_pos) * (fdf->size + 1));
	allocate_ierror(fdf->int_map);
	fdf->x_angle = 30;
	fdf->y_angle = 30;
	read_map(argv, fdf);
	center_coordinates(fdf, fdf->map, i);
	center_coordinates(fdf, fdf->i_map, i);
}