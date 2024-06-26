/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 00:20:12 by eonoh             #+#    #+#             */
/*   Updated: 2024/06/26 23:07:30 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*void ft_putchar(char c)
{
    write(1, &c, 1);
}

int deal_key()
{
    ft_putchar('x');
    return 0;
}*/

// map 이 .fdf로 안끝나면 exit
int main(int argc, char **argv)
{
    t_window window;
    t_data  image;
	t_map	fdf;

	check_argc(argc);
	set_window(&window, &image);
	set_map(argv[1], &fdf);
	for (int i = 0; i < fdf.size; i++)
	{
		fdf.int_map[i].x = (int)(fdf.i_map[i].x);
		fdf.int_map[i].y = (int)(fdf.i_map[i].y);
		fdf.int_map[i].z = (int)(fdf.i_map[i].z);
		fdf.int_map[i].color = (int)(fdf.i_map[i].color);
		printf("isometric[%d] x = %d y = %d\n", i, fdf.int_map[i].x, fdf.int_map[i].y);
	}
	// draw(fdf.i_map, fdf.size, &image);
	draw_line(&fdf, &image);
	mlx_put_image_to_window(window.mlx_ptr, window.win_ptr, image.img, 0, 0);
	mlx_loop(window.mlx_ptr);

	return 0;
}