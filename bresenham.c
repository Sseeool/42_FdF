/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 16:21:48 by eonoh             #+#    #+#             */
/*   Updated: 2024/06/29 03:22:09 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_value(t_ipos start, t_ipos end, t_map *fdf)
{
	if (start.x < end.x)
		fdf->x_value = 1;
	else
		fdf->x_value = -1;
	if (start.y < end.y)
		fdf->y_value = 1;
	else
		fdf->y_value = -1;
}

void	draw_shallow(t_ipos start, t_ipos end, t_data *image, t_map *fdf)
{
	int	disc;

	disc = 2 * (fdf->h) - fdf->w;
	while (start.x != end.x)
	{
		if (disc < 0)
			disc += (2 * fdf->h);
		else
		{
			start.y += fdf->y_value;
			disc += 2 * (fdf->h - fdf->w);
		}
		my_mlx_pixel_put(image, start.x, start.y, fdf->i_map[fdf->i].color);
		start.x += fdf->x_value;
	}
}

void	draw_steep(t_ipos start, t_ipos end, t_data *image, t_map *fdf)
{
	int	disc;

	disc = 2 * (fdf->w) - fdf->h;
	while (start.y != end.y)
	{
		if (disc < 0)
			disc += 2 * (fdf->w);
		else
		{
			start.x += fdf->x_value;
			disc += 2 * (fdf->w - fdf->h);
		}
		my_mlx_pixel_put(image, start.x, start.y, fdf->i_map[fdf->i].color);
		start.y += fdf->y_value;
	}
}

void	bresenham(t_ipos start, t_ipos end, t_data *image, t_map *fdf)
{
	get_value(start, end, fdf);
	fdf->w = abs(end.x - start.x);
	fdf->h = abs(end.y - start.y);
	if (fdf->w > fdf->h)
		draw_shallow(start, end, image, fdf);
	else
		draw_steep(start, end, image, fdf);
}
