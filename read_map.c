#include "minilibx-linux/mlx.h"
#include "fdf.h"
#include "get_next_line/get_next_line.h"
#include <stdio.h>
#include "libft/libft.h"

int	*get_map_data(char *maps, l_data **line_data)
{
	char	*start;
	int	x;
	int	y;

	y = 0;
	start = maps;
	while (maps)
	{
		while (*maps == '\n')
		{
			x = 0;
			while (maps >= '0' && maps <= '9')
				maps++;
			(**line_data).z = ft_atoi(start);
			(**line_data).x = x++;
			(**line_data).y = y;

		}
	}
}

void	read_map(int argc, char *argv, char **maps)
{
	l_data *line_data;
	char	*line;
	int		offset;
	int		fd;
	int		y;

	if (!(argc == 2))
        return ;
	y = 0;
	*maps = ft_strdup("");
    fd = open(argv, O_RDONLY);
    while (1)
    {
        line = get_next_line(fd);

        if (line == NULL)
            break;
		y++;
        *maps = ft_strjoin(*maps, line);
        free(line);
    }
    close(fd);
    printf("%s\n", *maps);
	printf("y = %d\n", y);
}