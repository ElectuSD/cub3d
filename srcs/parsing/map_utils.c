/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 13:25:10 by fdeleard          #+#    #+#             */
/*   Updated: 2025/08/06 11:48:54 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdbool.h>

static bool	is_valid_map_dir(char c);
static bool	is_valid_map_char(char c);
static bool	is_valid_map_wall(char c);

bool	is_valid_map_line(char *line)
{
	static bool	has_direction = false;

	while (line && *line)
	{
		if (!is_valid_map_char(*line))
		{
			printf("Non valid character in map : %c\n", *line);
			return (false);
		}
		if (is_valid_map_dir(*line) && has_direction)
		{
			printf("Multiple direction for player spawn in map : %c\n", *line);
			return (false);
		}
		if (is_valid_map_dir(*line))
			has_direction = true;
		line++;
	}
	return (true);
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
	return (c == '\n' || c == ' ' || c == '0' || c == '1');
}
