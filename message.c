#include "minilibx-linux/mlx.h"
#include "fdf.h"
#include "get_next_line/get_next_line.h"
#include <stdio.h>
#include "libft/libft.h"

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