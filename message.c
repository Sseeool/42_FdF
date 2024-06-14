/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 04:23:48 by eonoh             #+#    #+#             */
/*   Updated: 2024/06/07 04:23:53 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


void	allocate_newstruct_error(line_data *new_struct)
{
	if (!new_struct)
	{
		perror("Failed to allocate new_struct memory.");
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

void	allocate_struct1_error(line_data *struct1, char **line, int fd)
{
	if (!struct1)
	{
		perror("Failed to allocate struct1");
		free(*line);
		close(fd);
		exit(1);
	}
}

void	allocate_struct2_error(line_data *struct2, line_data **struct1, char **line, int fd)
{
	if (!struct2)
	{
		perror("Failed to allocate struct2");
		free(*line);
		free(*struct1);
		close(fd);
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