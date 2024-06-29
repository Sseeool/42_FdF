/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 00:19:11 by eonoh             #+#    #+#             */
/*   Updated: 2024/06/29 23:15:25 by eonoh            ###   ########.fr       */
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
