/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 11:34:42 by fdeleard          #+#    #+#             */
/*   Updated: 2025/08/06 14:28:14 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "libft_str.h"
#include "cub3d_parsing.h"

bool	is_texture(char *line)
{
	if (!line)
		return (false);
	return (is_north(line) || is_south(line) || is_east(line) || is_west(line));
}

bool	is_north(char *line)
{
	return ((ft_strncmp(line, "NO", 2) == 0));
}

bool	is_south(char *line)
{
	return ((ft_strncmp(line, "SO", 2) == 0));
}

bool	is_west(char *line)
{
	return ((ft_strncmp(line, "WE", 2) == 0));
}

bool	is_east(char *line)
{
	return ((ft_strncmp(line, "EA", 2) == 0));
}
