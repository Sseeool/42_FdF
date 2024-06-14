/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 19:19:37 by eonoh             #+#    #+#             */
/*   Updated: 2024/06/13 20:09:30 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fdf.h"

int	get_x_size(line_data *struct1)
{
	int	x;

	x = 0;
	while (struct1[x].y < 1)
		x++;
	return (x);
}

void	isometric(line_data *struct1, int size)
{
	int	i;
	double	pi;

	i = 0;
	pi = 3.14;
	while (i < size)
	{
		struct1[i].x = struct1[i].x * cos(ANGLE * pi / 180) - struct1[i].y * cos(ANGLE * pi / 180);
		struct1[i].y = struct1[i].x * sin(ANGLE * pi / 180) - struct1[i].z;
		struct1[i].x += 100;
		struct1[i].y += 100;
		printf("x: %d y: %d\n", struct1[i].x, struct1[i].y);
		i++;
	}
}

void	draw(line_data *struct1, int size, t_data *image)
{
	int	i;

	i = 0;
	while (i < size)
	{
		//printf("\n\n###draw %d %d %d", struct1[i].x + 500, struct1[i].y + 500, struct1[i].color);
		my_mlx_pixel_put(image, struct1[i].x, struct1[i].y, struct1[i].color);
		//mlx_pixel_put (window->mlx_ptr, window->win_ptr, struct1[i].x, struct1[i].y, struct1[i].color);
		i++;
	}
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

//void	draw_line(line_data *struct1, t_data *image)
//{
//	int	i;

//	//while (i < x_max * y_max)
//	//{
//	//	//printf("\n\n###draw %d %d %d", struct1[i].x + 500, struct1[i].y + 500, struct1[i].color);
//	//	my_mlx_pixel_put(image, struct1[i].x, struct1[i].y, struct1[i].color);
//	//	//mlx_pixel_put (window->mlx_ptr, window->win_ptr, struct1[i].x, struct1[i].y, struct1[i].color);
//	//	i++;
//	i = struct1[0].x;

//	while (struct1[i].y < struct1[i].y + 1)
//	{
//		my_mlx_pixel_put(image, struct1[i].x, struct1[i].y, struct1[i].color);
//		i++;
//		if (struct1[i].color == -1)
//			break;
//	}
//}