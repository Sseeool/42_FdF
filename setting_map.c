/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 20:28:22 by eonoh             #+#    #+#             */
/*   Updated: 2024/06/14 04:10:12 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	check_pos_range(map_range pos_range)
{
	int	negative_offset;

	negative_offset = 0;
	if (pos_range.x_min < 0)
		negative_offset = pos_range.x_max;
	if (pos_range.y_min < 0)
		negative_offset = pos_range.y_min;
	return (negative_offset);
}

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

map_range	get_scale(map_range pos_range)
{
	int	width;
	int	height;

	width = pos_range.x_max - pos_range.x_min;
	height = pos_range.y_max - pos_range.y_min;
}

//int	get_scale(line_data *map_pos, int x_size, int y_size)
//{
//	int	scale;

//	scale = 1;
//	while (x_size < )
//}