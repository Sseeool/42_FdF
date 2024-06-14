/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 04:24:07 by eonoh             #+#    #+#             */
/*   Updated: 2024/06/14 04:10:16 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_map_size(char *argv)
{
	int	fd;
	int	x;
	int	y;
	char	*line;

	y = 0;
	fd = open(argv, O_RDONLY);
	line = get_next_line(fd);
	y++;
	x = count_word(line, ' ');
	free(line);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		y++;
		free(line);
	}
	return (x * y);
}

int	count_word(char *s, char c)
{
	int	cnt;
	int flag;

	cnt = 0;
	flag = 1;
	while (*s != '\n' && *s)
	{
		if (flag == 1 && *s != c)
		{
			cnt++;
			flag = 0;
		}
		if (*s == c)
			flag = 1;
		s++;
	}
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

map_range	get_map_data(char *line, line_data *struct1, int y, int *i)
{
	char	*start;
	int		x;
	map_range	pos_range;

	x = 0;
	while (*line != '\n' && *line != '\0')
	{
		start = line;
		while (!((*line >= '0' && *line <= '9') || *line == '-'))
			line++;
		while (((*line >= '0' && *line <= '9') || *line == '-') && *line)
			line++;
		struct1[*i].z = ft_atoi(start);
		struct1[*i].x = x;
		x++;
		struct1[*i].y = y;
		struct1[*i].color = get_color(&line);
		while (*line == ' ' && *line)
			line++;
		set_coordinate_bounds(&pos_range, *i, struct1[*i]);
		// printf("struct[%d].z = %d x = %d y = %d color = %d\n", *i, struct1[*i].z, struct1[*i].x, struct1[*i].y, struct1[*i].color);
		(*i)++;
	}
	struct1[*i].color = -1;
	return (pos_range);
}

line_data *read_map(char *argv, int *y, int size, map_range	*pos_range)
{
	char *line;
	line_data *struct1;
	int fd;
	int	i;

	fd = open(argv, O_RDONLY);
	open_file_error(fd);
	struct1 = (line_data *)malloc(sizeof(line_data) * ((size) + 1));
	allocate_struct1_error(struct1, &line, fd);
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		*pos_range = get_map_data(line, struct1, (*y)++, &i);
		free(line);
	}
	//for (int i = 0; i < size; i++) {
	//	printf("x: %d y: %d z: %d color: %d\n", struct1[i].x, struct1[i].y, struct1[i].z, struct1[i].color);
	//}
	close(fd);
	return (struct1);
}