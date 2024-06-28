/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 00:19:11 by eonoh             #+#    #+#             */
/*   Updated: 2024/06/29 04:10:02 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	error_message(char *s)
{
	write(2, s, ft_strlen(s));
	exit(1);
}

void	is_valid_arg(char *s)
{
	int	idx;

	idx = ft_strlen(s) - 4;
	if (ft_strncmp(s + idx, ".fdf", 4) != 0)
		error_message("Invalid argument error.\n");
}

void	is_valid_map(char *s)
{
	if (!(*s && ((*s >= '0' && *s <= '9') \
		|| *s == ' ' || *s == ',' || *s == '-' || *s == '\n')))
		error_message("Invalid map error.\n");
}
