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

# ifndef WIDTH
#  define WIDTH	1920
# endif

# ifndef HEIGHT
#  define HEIGHT	1080
# endif

# ifndef BLANK
#  define	BLANK	400
# endif

#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line/get_next_line.h"
#include "libft/libft.h"
#include "minilibx_macos/mlx.h"

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_window
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_window;

typedef struct s_range
{
	double	x_min;
	double	x_max;
	double	y_max;
	double	y_min;
} t_range;

typedef struct	s_pos
{
	double	x;
	double	y;
	int	z;
	int	color;
} t_pos;

typedef struct s_ipos
{
	int	x;
	int	y;
	int	z;
	int	color;
} t_ipos;


typedef struct	s_map
{
	t_range	range;
	t_pos	*map;
	t_pos	*i_map;
	t_ipos	*int_map;
	int		x_angle;
	int		y_angle;
	int		x_value;
	int		y_value;
	int		w;
	int		h;
	int		size;
	int		x_size;
	int		y_size;
	int		i;
}	t_map;

// fdf.c


//error.c
void	allocate_error(t_pos *new_struct);
void	allocate_ierror(t_ipos *new_struct);
void	open_file_error(int fd);
void	check_argc(int argc);
void	invalid_color_error(char c);

// setting.c
void	set_window(t_window *window, t_data *image);
void	set_map(char *argv, t_map *fdf);

// read_map.c
int		get_map_size(char *argv, t_map *fdf);
void	get_map_data(char *line, int y, t_map *fdf, int *i);
int		get_color(char **s);
int		count_word(char *s, char c);
void 	read_map(char *argv, t_map *fdf);

// draw.c
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	draw(t_pos *struct1, int size, t_data *image);
void	isometric(t_map *fdf, int i);

// center.c
void	set_coordinate_bounds(t_map *fdf, t_pos *map, int i);
int		get_scale(t_range range);
int		get_x_offset(t_range range, int scale, double shift_x);
int		get_y_offset(t_range range, int scale, double shift_y);
void	center_coordinates(t_map *fdf, t_pos *map, int i);

// bresenham.c
void	get_value(t_ipos start, t_ipos end, t_map *fdf);
void	draw_shallow(t_ipos start, t_ipos end, t_data *image, t_map *fdf);
void	draw_steep(t_ipos start, t_ipos end, t_data *image, t_map *fdf);
void	bresenham(t_ipos start, t_ipos end, t_data *image, t_map *fdf);
void	draw_line(t_map *fdf, t_data *image);

#endif