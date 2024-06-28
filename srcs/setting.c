/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 20:08:21 by eonoh             #+#    #+#             */
/*   Updated: 2024/06/29 03:55:48 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	set_window(t_window *window, t_data *image)
{
	window->mlx_ptr = mlx_init();
	window->win_ptr = \
	mlx_new_window(window->mlx_ptr, WIDTH, HEIGHT, "My Window");
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

void	set_mapdup(t_map *fdf)
{
	int	i;

	i = 0;
	while (i < fdf->size)
	{
		fdf->int_map[i].x = (int)(fdf->i_map[i].x);
		fdf->int_map[i].y = (int)(fdf->i_map[i].y);
		fdf->int_map[i].z = (int)(fdf->i_map[i].z);
		fdf->int_map[i].color = (int)(fdf->i_map[i].color);
		i++;
	}
	fdf->int_map[i].color = -1;
}
