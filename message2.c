/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 19:54:14 by eonoh             #+#    #+#             */
/*   Updated: 2024/06/04 00:50:56 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include "fdf.h"
#include "get_next_line/get_next_line.h"
#include "libft/libft.h"

void	invalid_color_error(char c)
{
	if ((!c && !(c == ' ') && !(c == '\n')))
	{
		perror("Invalid color");
		exit(1);
	}
}