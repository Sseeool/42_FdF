/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 08:43:56 by eonoh             #+#    #+#             */
/*   Updated: 2024/06/29 08:44:40 by eonoh            ###   ########.fr       */
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
