/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 00:15:39 by eonoh             #+#    #+#             */
/*   Updated: 2024/06/29 03:55:32 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	press_distory_btn(int key, t_window *window)
{
	if (!window)
		return (0);
	if (key)
		exit(0);
	return (1);
}

int	mlx_close(t_window *window)
{
	mlx_destroy_image(window->mlx_ptr, window->data->img);
	mlx_destroy_window(window->mlx_ptr, window->win_ptr);
	mlx_destroy_display(window->mlx_ptr);
	free(window->mlx_ptr);
	exit(0);
}

int	key_press(int key, t_window *window)
{
	if (key == 65307)
		mlx_close(window);
	return (0);
}
