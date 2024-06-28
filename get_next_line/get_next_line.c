/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 22:30:53 by eonoh             #+#    #+#             */
/*   Updated: 2024/05/22 21:52:15 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	find_newline(char *backup)
{
	int	i;

	i = 0;
	while (backup[i])
	{
		if (backup[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*get_temp(char **backup, char *buf, int fd, int *i)
{
	int		read_bytes;

	if (*backup == NULL)
		*backup = ft_strdup("");
	while (1)
	{
		read_bytes = read(fd, buf, BUFFER_SIZE);
		if (read_bytes >= 0)
			buf[read_bytes] = '\0';
		if ((read_bytes == 0 && *backup[0] == '\0') || read_bytes == -1)
		{
			free(*backup);
			*backup = NULL;
			return (0);
		}
		if (buf[0] != '\0')
			*backup = ft_strjoin2(*backup, buf);
		*i = find_newline(*backup);
		if (*i != -1 || (*i == -1 && read_bytes == 0))
			return (*backup);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*result;
	char		*temp;
	char		*buf;
	int			i;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (0);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	temp = get_temp(&backup, buf, fd, &i);
	free(buf);
	buf = NULL;
	if (temp == NULL)
		return (NULL);
	if (i == -1)
	{
		backup = NULL;
		return (temp);
	}
	result = ft_substr(temp, 0, i + 1);
	backup = ft_substr(temp, i + 1, ft_strlen(temp));
	free(temp);
	return (result);
}
