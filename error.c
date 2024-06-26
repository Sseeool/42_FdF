/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 00:19:11 by eonoh             #+#    #+#             */
/*   Updated: 2024/06/26 23:01:06 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	allocate_error(t_pos *new_struct)
{
	if (!new_struct)
	{
		perror("Failed to allocate new struct memory.");
		exit(1);
	}
}

void	allocate_ierror(t_ipos *new_struct)
{
	if (!new_struct)
	{
		perror("Failed to allocate new struct memory.");
		exit(1);
	}
}

void	open_file_error(int fd)
{
	if (fd == -1)
	{
		perror("Failed to open file.");
		exit(1);
	}
}

void	check_argc(int argc)
{
    if (argc != 2)
    {
		perror ("FDF program expects 2 arguments.");
		exit(1);
	}
}

void	invalid_color_error(char c)
{
	if ((!c && !(c == ' ') && !(c == '\n')))
	{
		perror("Invalid color");
		exit(1);
	}
}