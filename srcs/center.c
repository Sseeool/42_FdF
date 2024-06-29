/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   center.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 20:28:22 by eonoh             #+#    #+#             */
/*   Updated: 2024/06/29 20:05:17 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	get_pos_range(t_map *fdf, t_pos *map, int i)
{
	if (i == 0)
	{
		fdf->range.x_max = map[i].x;
		fdf->range.x_min = map[i].x;
		fdf->range.y_max = map[i].y;
		fdf->range.y_min = map[i].y;
		return ;
	}
	if (fdf->range.x_max < map[i].x)
		fdf->range.x_max = map[i].x;
	if (fdf->range.x_min > map[i].x)
		fdf->range.x_min = map[i].x;
	if (fdf->range.y_max < map[i].y)
		fdf->range.y_max = map[i].y;
	if (fdf->range.y_min > map[i].y)
		fdf->range.y_min = map[i].y;
}

int	get_scale(t_range range)
{
	int	width;
	int	height;
	int	scale;

	width = (WIDTH - BLANK) / (range.x_max - range.x_min);
	height = (HEIGHT - BLANK) / (range.y_max - range.y_min);
	((width > height) && (scale = height)) || \
	((width <= height) && (scale = width));
	return (scale);
}

int	get_x_offset(t_range range, int scale, double shift_x)
{
	int	x_offset;

	range.x_max = (range.x_max + shift_x) * scale;
	range.x_min = (range.x_min + shift_x) * scale;
	x_offset = (WIDTH / 2) - ((range.x_max - range.x_min) / 2);
	return (x_offset);
}

int	get_y_offset(t_range range, int scale, double shift_y)
{
	double	y_offset;

	range.y_max = (range.y_max + shift_y) * scale;
	range.y_min = (range.y_min + shift_y) * scale;
	y_offset = (HEIGHT / 2) - ((range.y_max - range.y_min) / 2);
	return (y_offset);
}

void	put_center(t_map *fdf, t_pos *map, int i)
{
	int		scale;
	double	x_offset;
	double	y_offset;
	double	shift_x;
	double	shift_y;

	scale = get_scale(fdf->range);
	if (fdf->range.x_min > 0)
		shift_x = fdf->range.x_min;
	else
		shift_x = fdf->range.x_min * -1;
	if (fdf->range.y_min > 0)
		shift_y = fdf->range.y_min;
	else
		shift_y = fdf->range.y_min * -1;
	x_offset = get_x_offset(fdf->range, scale, shift_x);
	y_offset = get_y_offset(fdf->range, scale, shift_y);
	while (map[i].color != -1)
	{
		map[i].x = (map[i].x + shift_x) * scale + x_offset;
		map[i].y = (map[i].y + shift_y) * scale + y_offset;
		i++;
	}
}
