/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 11:40:22 by fdeleard          #+#    #+#             */
/*   Updated: 2025/11/13 10:02:39 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_str.h"

#include "cub3d_parsing.h"

bool	is_color(char *line)
{
	if (!line)
		return (false);
	return (is_floor(line) || is_ceiling(line));
}

bool	is_floor(char *line)
{
	if (ft_strlen(line) == 0)
		return (false);
	return (ft_strncmp(line, "F", 1) == 0
		&& (line[1] == '\0' || line[1] == ' ' || line[1] == '\t'));
}

bool	is_ceiling(char *line)
{
	if (ft_strlen(line) == 0)
		return (false);
	return (ft_strncmp(line, "C", 1) == 0
		&& (line[1] == '\0' || line[1] == ' ' || line[1] == '\t'));
}
