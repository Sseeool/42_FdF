
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <fcntl.h>

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
	struct l_data	*next;
}	line_data;

typedef struct window_data
{
	void	*mlx_ptr;
	void	*win_ptr;
}	window_data;


void	read_map(int argc, char *argv, char **maps);
