/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 04:24:07 by eonoh             #+#    #+#             */
/*   Updated: 2024/06/29 23:15:35 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	get_map_size(char *argv, t_map *fdf)
{
	int		fd;
	char	*line;

	fdf->y_size = 0;
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		error_message("Failed to open file.\n");
	line = get_next_line(fd);
	(fdf->y_size)++;
	fdf->x_size = count_word(line, ' ');
	free(line);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (count_word(line, ' ') != fdf->x_size)
			error_message("Invalid map format: Not a rectangle.\n");
		(fdf->y_size)++;
		free(line);
	}
	return ((fdf->x_size) * (fdf->y_size));
}

int	count_word(char *s, char c)
{
	int	cnt;
	int	flag;

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
	int	num;

	result = 0;
	num = 0;
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
		num++;
	}
	if ((!(**s == ' ') && !(**s == '\n')) || num > 6)
		error_message("Invalid color error.\n");
	return (result);
}

void	get_map_data(char *line, int y, t_map *fdf, int *i)
{
	char	*start;
	int		x;

	x = 0;
	while (*line != '\n' && *line != '\0')
	{
		start = line;
		while (!((*line >= '0' && *line <= '9') || *line == '-'))
			line++;
		while (((*line >= '0' && *line <= '9') || *line == '-') && *line)
			line++;
		fdf->map[*i].z = ft_atoi(start);
		fdf->map[*i].x = x;
		x++;
		fdf->map[*i].y = y;
		fdf->map[*i].color = get_color(&line);
		while (*line == ' ' && *line)
			line++;
		get_pos_range(fdf, fdf->map, *i);
		isometric(fdf, *i);
		(*i)++;
	}
}

void	read_map(char *argv, t_map *fdf)
{
	char	*line;
	int		fd;
	int		i;
	int		y;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
		error_message("Failed to open file.\n");
	i = 0;
	y = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		get_map_data(line, y++, fdf, &i);
		free(line);
	}
	fdf->map[i].color = -1;
	fdf->i_map[i].color = -1;
	close(fd);
}
