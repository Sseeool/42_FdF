#include "minilibx-linux/mlx.h"
#include "fdf.h"
#include "get_next_line/get_next_line.h"
#include <stdio.h>
#include "libft/libft.h"

int	*get_map_data(char *line, line_data **maps, int y)
{
	char	*start;
	int	x;
	int	z;

	start = line;
	while (line)
	{
		x = 0;
		while (*line >= '0' && *line <= '9' || *line)
			line++;
		(**maps).z = ft_atoi(start);
		(**maps).x = x++;
		(**maps).y = y;
		if (*line == ' ')
			line++;
		if (*line == ',')
		{
			start = ++line;
			if (!(*line >= '0' && *line <= '9'))
				print_error();
			while (*line >= '0' && *line <= '9' || *line)
				line++;
			(**maps).color = 
		}
	}
}

// get_next_line을 이용해서 파일 읽고, maps라는 아주 큰 일차원배열에 다
void	read_map(int argc, char *argv, line_data **maps)
{
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