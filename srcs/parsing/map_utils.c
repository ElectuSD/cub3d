/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 13:25:10 by fdeleard          #+#    #+#             */
/*   Updated: 2025/08/19 10:36:44 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "cub3d_parsing.h"

static bool	is_valid_map_dir(char c);
static bool	is_valid_map_char(char c);
static bool	is_valid_map_wall(char c);

bool	is_valid_map_line(t_map_info *infos, char *line)
{
	while (line && *line)
	{
		if (!is_valid_map_char(*line))
		{
			printf("Error\nNon valid character in map : %c\n", *line);
			return (false);
		}
		if (is_valid_map_dir(*line) && infos->has_player)
		{
			printf("Error\nMultiple direction for player spawn in map : %c\n",
				*line);
			return (false);
		}
		if (is_valid_map_dir(*line))
			infos->has_player = true;
		line++;
	}
	return (true);
}

size_t	get_map_size(char **map)
{
	size_t	size;

	size = 0;
	while (map[size])
		size++;
	return (size);
}

static bool	is_valid_map_char(char c)
{
	return (is_valid_map_wall(c) || is_valid_map_dir(c));
}

static bool	is_valid_map_dir(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

static bool	is_valid_map_wall(char c)
{
	return (c == '\t' || c == '\n' || c == ' ' || c == '0' || c == '1');
}
