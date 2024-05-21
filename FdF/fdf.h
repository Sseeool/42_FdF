
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