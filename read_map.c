#include "minilibx-linux/mlx.h"
#include "fdf.h"
#include "get_next_line/get_next_line.h"
#include <stdio.h>
#include "libft/libft.h"

int	count_struct(line_data *struct1)
{
	int cnt;

	cnt = 0;
	while (struct1[cnt].color != -1)
		cnt++;
	return (cnt);
}

int	get_color(char **s)
{
	int	result;

	result = 0;
	if (**s != ',')
		return (COLOR_DEFAULT);
	(*s)++;
	if ((**s == '0' && *(*s + 1) == 'x'))
		*s += 2;
	while ((**s >= '0' && **s <= '9') || (**s >= 'a' && **s <= 'f') || \
			(**s >= 'A' && **s <= 'F'))
	{
		if (**s >= '0' && **s <= '9')
			result = result * 16 + (**s - '0');
		else if (**s >= 'a' && **s <= 'f')
			result = result * 16 + (**s - 'a' + 10);
		else
			result = result * 16 + (**s - 'A' + 10);
		(*s)++;
	}
	invalid_color_error(**s);
	return (result);
}

void	get_map_data(char *line, line_data *struct1, int y)
{
	char	*start;
	int		x;

	x = 0;
	while (*line != '\n' && *line != '\0')
	{
		start = line;
		printf("y = %d line = %c\n", y, *line);
		while (((*line >= '0' && *line <= '9') || *line == '-') && *line)
			line++;
		struct1->z = ft_atoi(start) * SCALE;
		struct1->x = x * SCALE;
		x++;
		struct1->y = y * SCALE;
		struct1->color = get_color(&line);
		while (*line == ' ' && *line)
			line++;
		struct1++;
	}
	struct1->color = -1;
}

void join_struct(line_data **struct1, line_data **struct2)
{
    int len1;
    int len2;
    int i;
    int j;
    line_data *new_struct;

	i = 0;
    j = 0;
    len1 = count_struct(*struct1);
    len2 = count_struct(*struct2);
    new_struct = (line_data *)malloc(sizeof(line_data) * (len1 + len2 + 1));
    allocate_newstruct_error(new_struct);
    while (i < len1)
    {
        new_struct[i] = (*struct1)[i];
        ++i;
    }
    while (j < len2)
        new_struct[i++] = (*struct2)[j++];
    new_struct[i].color = -1;
    free(*struct1);
    *struct1 = new_struct;
    free(*struct2);
    *struct2 = NULL;
}

line_data *read_map(char *argv, int *size)
{
	char *line;
	line_data *struct1;
	line_data *struct2;
	int fd;
	int y;

	y = 0;
	fd = open(argv, O_RDONLY);
	open_file_error(fd);
	line = get_next_line(fd);
	struct1 = (line_data *)malloc(sizeof(line_data) * ((ft_strlen(line) / 2) + 1));
	allocate_struct1_error(struct1, &line, fd);
	get_map_data(line, struct1, y++);
	free(line);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		struct2 = (line_data *)malloc(sizeof(line_data) * ((ft_strlen(line) / 2) + 1));
		allocate_struct2_error(struct2, &struct1, &line, fd);
		get_map_data(line, struct2, y++);
		join_struct(&struct1, &struct2);
		free(line);
	}
    for (int i = 0; struct1[i].color != -1; i++) {
        printf("x: %d y: %d z: %d color: %d\n", struct1[i].x, struct1[i].y, struct1[i].z, struct1[i].color);
    }
	*size = get_map_size(struct1, y);
	close(fd);
	return (struct1);
}