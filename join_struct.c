#include <stdio.h>
#include <stdlib.h>
#include <string.h>

# ifndef COLOR_DEFAULT
#  define COLOR_DEFAULT 0xFFFFFF
# endif

typedef struct	line_data
{
	int	x;
	int	y;
	int	z;
	int	color;
}	line_data;

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	num;

	sign = 1;
	num = 0;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
	{
		nptr++;
	}
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
		{
			sign = -1;
		}
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		num = num * 10 + (*nptr - '0');
		nptr++;
	}
	return (sign * num);
}

int	count_struct(line_data *struct1)
{
	int cnt;

	cnt = 0;
	while (struct1[cnt].color != -1)
		cnt++;
	return (cnt);
}

int	get_color(char *s)
{
	int	result;
	int	alphabet_count;

	alphabet_count = 9;
	if (!(*s == '0' && *(s + 1) == 'x'))
	{
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
		return (1);
	}
	return (result);
}

void	get_map_data(char *line, line_data *new_line, int y)
{
	char	*start;
	int	x;

	x = 0;
	while (*line)
	{
		start = line;
		while ((*line >= '0' && *line <= '9') && *line)
			line++;
		(new_line)->z = ft_atoi(start);
		(new_line)->x = x++;
		(new_line)->y = y;
		if (*line == ',')
		{
			start = ++line;
			while ((*line >= '0' && *line <= '9') && *line)
				line++;
			(new_line)->color = get_color(start);
		}
		else
			(new_line)->color = COLOR_DEFAULT;
		while (*line == ' ' && *line)
			line++;
		(new_line)++;
	}
	(new_line)->color = -1;
}


void join_struct(line_data **struct1, line_data **struct2) {
    int len1, len2, new_len;
    int i, j;
    line_data *new_struct;

	i = 0;
    len1 = count_struct(*struct1);
    len2 = count_struct(*struct2);
    new_len = len1 + len2;

    new_struct = (line_data *)malloc(sizeof(line_data) * (new_len + 1));
    if (new_struct == NULL)
	{
        perror("Failed to allocate memory");
        exit(1);
    }

    for (i = 0; i < len1; i++)
	{
        new_struct[i].x = (*struct1[i]).x;
		new_struct[i].y = (*struct1[i]).y;
		new_struct[i].z = (*struct1[i]).z;
		new_struct[i].color = (*struct1[i]).color;
    }

    for (j = 0; j < len2; j++, i++)
	{
        new_struct[i].x = (*struct2[i]).x;
		new_struct[i].y = (*struct2[i]).y;
		new_struct[i].z = (*struct2[i]).z;
		new_struct[i].color = (*struct2[i]).color;
    }

    new_struct[new_len].color = -1;

    free(*struct1);
    *struct1 = new_struct;

    free(*struct2);
    *struct2 = NULL;
}

int main()
{
	char *s1 = "1 0 0 1 1 0 1 1 0 0"; //30
	char *s2 = "1 0 0 0 1 0 0 0 0 0"; //40
	line_data *struct1;
	line_data *struct2;

	int	len;
	int	i;
	int j;

	i = 0;
	j = 0;
	struct1 = (line_data *)malloc(sizeof(line_data) * ((strlen(s1) / 2) + 1));
	struct2 = (line_data *)malloc(sizeof(line_data) * ((strlen(s2) / 2)+ 1));

	printf("get_map_data start!");
	get_map_data(s1, struct1, 0);
	get_map_data(s2, struct2, 0);
	printf("get_map_data end!");

	join_struct(&struct1, &struct2);
	for (int i = 0; struct1[i].color != -1; i++)
	{
		printf("x: %d y: %d z: %d color: %d\n", struct1[i].x, struct1[i].y, struct1[i].z, struct1[i].color);
	}
	return 0;
}