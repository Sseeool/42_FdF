/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 19:19:37 by eonoh             #+#    #+#             */
/*   Updated: 2024/06/26 23:03:31 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	fdf->i_map[i].y = (x + y) * sin(fdf->y_angle * pi / 180) - z * 0.5;
	set_coordinate_bounds(fdf, fdf->i_map, i);
}

void	draw(t_pos *map, int size, t_data *image)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	while (i < size)
	{
		x = (int)map[i].x;
		y = (int)map[i].y;
		my_mlx_pixel_put(image, x, y, map[i].color);
		i++;
	}
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}