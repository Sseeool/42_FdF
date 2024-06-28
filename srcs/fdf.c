/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 00:20:12 by eonoh             #+#    #+#             */
/*   Updated: 2024/06/29 03:55:41 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	main(int argc, char **argv)
{
	t_window	window;
	t_data		image;
	t_map		fdf;

	if (argc != 2)
		error_message("FDF program expects 2 arguments.\n");
	is_valid_arg(argv[1]);
	set_window(&window, &image);
	set_map(argv[1], &fdf);
	draw_line(&fdf, &image);
	mlx_put_image_to_window(window.mlx_ptr, window.win_ptr, image.img, 0, 0);
	mlx_key_hook(window.win_ptr, key_press, &window);
	mlx_hook(window.win_ptr, 17, 0, mlx_close, &window);
	mlx_loop(window.mlx_ptr);
	return (0);
}
