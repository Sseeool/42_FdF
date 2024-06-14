#ifndef FDF_H
# define FDF_H

# ifndef COLOR_DEFAULT
#  define COLOR_DEFAULT 0xFFFFFF
# endif

# ifndef SCALE
#  define SCALE	1
# endif

# ifndef ANGLE
#  define ANGLE	30
# endif

#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include "get_next_line/get_next_line.h"
#include "libft/libft.h"
#include "minilibx-linux/mlx.h"

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

typedef struct map_range
{
	int	x_min;
	int	x_max;
	int	y_max;
	int	y_min;
} map_range;

void	setting_window(window_data *window, t_data *image);
line_data *read_map(char *argv, int *y, int size, map_range	*pos_range);
void	print_error();
void	allocate_newstruct_error(line_data *new_struct);
void	open_file_error(int fd);
void	allocate_struct1_error(line_data *struct1, char **line, int fd);
void	allocate_struct2_error(line_data *struct2, line_data **struct1, char **line, int fd);
void	check_argc(int argc);
int		count_struct(line_data *struct1);
int		get_color(char **s);
void	get_map_data(char *line, line_data *struct1, int y, int *i);
void	join_struct(line_data **struct1, line_data **struct2);
void	invalid_color_error(char c);
int		get_x_size(line_data *struct1);
void	isometric(line_data *struct1, int size);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	draw(line_data *struct1, int size, t_data *image);
void	draw_line(line_data *struct1, int x_max, int y_max, t_data *image);
int		get_map_size(char *argv);
int		count_word(char *s, char c);
int		check_pos_range(map_range pos_range);
void	set_coordinate_bounds(map_range *pos_range, int i, line_data map_pos);

#endif