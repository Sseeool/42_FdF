#include "minilibx-linux/mlx.h"
#include "fdf.h"
#include "get_next_line/get_next_line.h"
#include <stdio.h>
#include "libft/libft.h"

int	count_struct(line_data *new_line)
{
	int	cnt;

	cnt = 0;
	while (new_line[cnt].end != 1)
		cnt++;
	return (cnt);
}

// 0x로 시작하지 않는 경우, 3채널에 값이 제대로 들어있지 않을 경우 오류
int	get_color(char *s)
{
	int	result;
	int	alphabet_count;

	alphabet_count = 9;
	if (!(*s == '0' && *(s + 1) == 'x'))
	{
		print_error();
		return (1);
	}
	s += 2;
	while (alphabet_count --> 0)
	{
		if (*s >= '0' && *s <= '9')
			result = result * 16 + (*s++ - '0');
		else if (*s >= 'a' && *s <= 'f')
			result = result * 16 + (*s++ - '0');
		else
			break;
	}
	if (!(*s || *s == ' '))
	{
		print_error();
		return (1);
	}
	return (result);
}

void	get_map_data(char *line, line_data **new_line, int y)
{
	char	*start;
	int	x;

	x = 0;
	while (line)
	{
		while ((*line >= '0' && *line <= '9') || *line)
			line++;
		(**new_line).z = ft_atoi(start);
		(**new_line).x = x++;
		(**new_line).y = y;
		if (*line == ',')
		{
			start = ++line;
			while ((*line >= '0' && *line <= '9') || *line)
				line++;
			(**new_line).color = get_color(start);
		}
		else
			(**new_line).color = COLOR_DEFAULT;
		while (*line == ' ' || *line)
			line++;
		new_line++;
	}
	(**new_line).end = 1;
}

void	copy_struct(line_data *dst, line_data *src, size_t size)
{
	while (size --> 0)
	{
		dst->x = src->x;
		dst->y = src->y;
		dst->z = src->z;
		dst->color = src->color;
	}
}

line_data	*join_struct(line_data *s1, line_data *s2)
{
	line_data	*p;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = count_struct(s1);
	s2_len = count_struct(s2);
	p = (line_data *)malloc(sizeof(line_data) * (s1_len + s2_len + 1));
	if (!p)
		return (0);
	copy_struct(p, s1, s1_len);
	copy_struct((p + s1_len), s2, s2_len);
	return (p);
}

// get_next_line을 이용해서 파일 읽고, maps라는 아주 큰 일차원배열에 다
void	read_map(int argc, char *argv, char **maps, line_data **map)
{
	char	*line;
	line_data	*new_line;
	int		line_len;
	int		fd;
	int		y;

	if (!(argc == 2))
        return ;
	y = 0;
	*maps = ft_strdup("");
    fd = open(argv, O_RDONLY);
	line = get_next_line(fd);
	line_len = ft_strlen(line);
	new_line = (line_data *)malloc(sizeof(line_data) * (line_len));
	get_map_data(line, &new_line, y);
	*maps = ft_strjoin(*maps, line);
	*map = join_struct(*map, new_line);
    free(line);
	free(new_line);
	for (int i = 0; map[i]->end != 1; i++)
	{
		printf("\n\n");
		printf("x = %d y = %d z = %d color = %d\n", new_line->x, new_line->y, new_line->z, new_line->color);
		printf("\n---------\n");
	}
    /*while (1)
    {
        line = get_next_line(fd);
		line_len = ft_strlen(line);
		new_line = (line_data *)malloc(sizeof(line_data) * (line_len));
		get_map_data(line, &new_line, y);

		for (int i = 0; new_line[i].end != 1; i++)
		{
			printf("\n\n");
			printf("x = %d y = %d z = %d color = %d\n", new_line->x, new_line->y, new_line->z, new_line->color);
			printf("\n---------\n");
		}
        if (line == NULL)
            break;
		y++;
        *maps = ft_strjoin(*maps, line);
		*map = join_struct(*map, new_line);
        free(line);
		free(new_line);
    }*/
    close(fd);
    printf("%s\n", *maps);
	printf("y = %d\n", y);
}
//구조체 배열을 널로 끝내서 .color가 null이 아닐때까지 돌리기