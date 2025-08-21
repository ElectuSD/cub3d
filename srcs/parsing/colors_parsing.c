/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 11:09:24 by fdeleard          #+#    #+#             */
/*   Updated: 2025/08/21 11:38:22 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_str.h"

#include "cub3d_map.h"
#include "cub3d_colors.h"
#include "cub3d_parsing.h"

static int	set_color_helper(t_parser *parser, char *identifier, t_rgb *color);
static int	set_color_map(bool *has_parsed, t_rgb *map_color, t_rgb *new_color);

int	parse_colors(t_parser *parser)
{
	int		ret;
	char	*line;
	char	*identifier;
	t_rgb	color;

	if (parser->parsing_map_done)
		return (MAP_NOT_LAST);
	line = trim_end_of_line(parser->line);
	identifier = ft_strtok(line, DEFAULT_TRIM);
	color.r = ft_atoi(ft_strtok(NULL, ","));
	color.g = ft_atoi(ft_strtok(NULL, ","));
	color.b = ft_atoi(ft_strtok(NULL, ","));
	ret = set_color_helper(parser, identifier, &color);
	return (ret);
}

static int	set_color_helper(t_parser *parser, char *identifier, t_rgb *color)
{
	if (is_ceiling(identifier))
	{
		if (set_color_map(&parser->c_done, &parser->map->ceiling, color))
			return (CEILING_DUPPLICATE);
	}
	if (is_floor(identifier))
	{
		if (set_color_map(&parser->f_done, &parser->map->floor, color))
			return (FLOOR_DUPPLICATE);
	}
	return (NO_ERRORS);
}

static int	set_color_map(bool *has_parsed, t_rgb *map_color, t_rgb *new_color)
{
	if (*has_parsed)
		return (PARSE_ERROR);
	map_color->r = new_color->r;
	map_color->g = new_color->g;
	map_color->b = new_color->b;
	*has_parsed = true;
	return (NO_ERRORS);
}
