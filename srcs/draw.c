/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 19:19:37 by eonoh             #+#    #+#             */
/*   Updated: 2024/06/29 03:55:35 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	isometric(t_map *fdf, int i)
{
	double	pi;
	double	x;
	double	y;
	int		z;

	pi = 3.1415926;
	fdf->i_map[i] = fdf->map[i];
	x = fdf->i_map[i].x;
	y = fdf->i_map[i].y;
	z = fdf->i_map[i].z;
	fdf->i_map[i].x = (x - y) * cos(fdf->x_angle * pi / 180);
	fdf->i_map[i].y = (x + y) * sin(fdf->y_angle * pi / 180) - z * Z_SCALE;
	get_pos_range(fdf, fdf->i_map, i);
}

void	draw_line(t_map *fdf, t_data *image)
{
	int	i;
	int	x_size;

	i = 0;
	x_size = fdf->x_size;
	while (i < fdf->size)
	{
		fdf->i = i;
		if (i + 1 < fdf->size && (i % x_size != x_size - 1))
			bresenham(fdf->int_map[i], fdf->int_map[i + 1], image, fdf);
		if (i + x_size < fdf->size)
			bresenham(fdf->int_map[i], fdf->int_map[i + x_size], image, fdf);
		i++;
	}
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
