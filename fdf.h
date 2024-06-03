#ifndef FDF_H
# define FDF_H

# ifndef COLOR_DEFAULT
#  define COLOR_DEFAULT 0xFFFFFF
# endif

#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct	line_data
{
	int	x;
	int	y;
	int	z;
	int	color;
}	line_data;

typedef struct window_data
{
	void	*mlx_ptr;
	void	*win_ptr;
}	window_data;

typedef struct	map
{
	line_data	pos;
} map;


void	read_map(char *argv);
void	print_error();
void	allocate_newstruct_error(line_data *new_struct);
void	open_file_error(int fd);
void	allocate_struct1_error(line_data *struct1, char **line, int fd);
void	allocate_struct2_error(line_data *struct2, line_data **struct1, char **line, int fd);
void	check_argc(int argc);
int		count_struct(line_data *struct1);
int		get_color(char **s);
void	get_map_data(char *line, line_data *struct1, int y);
void	join_struct(line_data **struct1, line_data **struct2);
void	invalid_color_error(char c);
int		get_map_size(line_data *struct1, int y);

#endif