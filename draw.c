/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 19:19:37 by eonoh             #+#    #+#             */
/*   Updated: 2024/06/05 03:49:35 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include "fdf.h"
#include "get_next_line/get_next_line.h"
#include "libft/libft.h"

int	get_map_size(line_data *struct1, int y)
{
	int	x;
	int	size;

	x = 0;
	while (struct1[x].y < 1)
		x++;
	size = x * y;
	printf("size = %d\n", size);
	return (size);
}

void	isometric(line_data *struct1, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		struct1[i].x = struct1[i].x * cos(ANGLE) - struct1[i].y * cos(ANGLE);
		struct1[i].y = struct1[i].x * sin(ANGLE) - struct1[i].z;
		i++;
	}
}

void	draw(line_data *struct1, int size, t_data *image)
{
	int	i;

	i = 0;
	if (!size || !image)
		return ;
	while (i < 10)
	{
		printf("\n\n###draw %d %d %d", struct1[i].x + 500, struct1[i].y + 500, struct1[i].color);
		my_mlx_pixel_put(image, struct1[i].x, struct1[i].y, struct1[i].color);
		i++;
	}
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}