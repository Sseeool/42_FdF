/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 20:28:22 by eonoh             #+#    #+#             */
/*   Updated: 2024/06/18 21:19:18 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//int	check_negative_pos(map_range pos_range)
//{
//	int	negative_offset;

//	negative_offset = 0;
//	if (pos_range.x_min < 0)
//		negative_offset = pos_range.x_max;
//	if (pos_range.y_min < 0)
//		negative_offset = pos_range.y_min;
//	return (negative_offset);
//}

// 좌표의 최대, 최솟값을 구해서 scale 조절에 활용
void	set_coordinate_bounds(map_range *pos_range, int i, line_data map_pos)
{
	if (i == 0)
	{
		pos_range->x_max = map_pos.x;
		pos_range->x_min = map_pos.x;
		pos_range->y_max = map_pos.y;
		pos_range->y_min = map_pos.y;
		return ;
	}
	if (pos_range->x_max < map_pos.x)
		pos_range->x_max = map_pos.x;
	if (pos_range->x_min > map_pos.x)
		pos_range->x_min = map_pos.x;
	if (pos_range->y_max < map_pos.y)
		pos_range->y_max = map_pos.y;
	if (pos_range->y_max < map_pos.y)
		pos_range->y_max = map_pos.y;
}

int	get_scale(map_range range)
{
	int	width;
	int	height;
	int	pos_width;
	int	pos_height;
	int scale;
	
	pos_width = range.x_max - range.x_min;
	pos_height = range.y_max - range.y_min;

	width = (WIDTH - 100) / pos_width;
	height = (HEIGHT - 100) / pos_height;
	((width > height) && (scale = height)) || ((width <= height) && (scale = height));
	return (scale);
}

int	get_x_offset(int size, int y, line_data *map_pos, int scale)
{
	int	i;
	int	x_offset;

	i = size / y / 2;
	x_offset = (WIDTH / 2) - (map_pos[i].x * scale);
	return (x_offset);
}

int	get_y_offset(int y, line_data *map_pos, int scale)
{
	int	i;
	int	y_offset;

	i = y / 2;
	y_offset = (HEIGHT / 2) - (map_pos[i].y * scale);
	return (y_offset);
}

void	center_coordinates(line_data *map_pos, map_range isometric_range, int size, int y)
{
	int	scale;
	int	x_offset;
	int	y_offset;
	int	i;

	scale = get_scale(isometric_range);
	i = 0;
	x_offset = get_x_offset(size, y, map_pos, scale);
	y_offset = get_y_offset(y, map_pos, scale);
	while (map_pos[i].color != -1)
	{
		map_pos[i].x = (map_pos[i].x + x_offset) * scale;
		map_pos[i].y = (map_pos[i].y + y_offset) * scale;
		i++;
	}
	map_pos[i].color = -1;
}

//int	get_scale(line_data *map_pos, int x_size, int y_size)
//{
//	int	scale;

//	scale = 1;
//	while (x_size < )
//}