/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 11:09:24 by fdeleard          #+#    #+#             */
/*   Updated: 2025/10/05 01:36:12 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_str.h"

#include "cub3d_map.h"
#include "cub3d_colors.h"
#include "cub3d_parsing.h"

static bool	cub3d_atoi(unsigned char *nb, const char *nptr);
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
	if (!cub3d_atoi(&color.r, ft_strtok(NULL, ",")))
		return (INVALID_COLOR);
	if (!cub3d_atoi(&color.g, ft_strtok(NULL, ",")))
		return (INVALID_COLOR);
	if (!cub3d_atoi(&color.b, ft_strtok(NULL, ",")))
		return (INVALID_COLOR);
	ret = set_color_helper(parser, identifier, &color);
	return (ret);
}

static bool	cub3d_atoi(unsigned char *nb, const char *nptr)
{
	int		prev_nb;
	size_t	i;

	i = 0;
	*nb = 0;
	if (!nptr)
		return (false);
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			return (false);
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		prev_nb = *nb;
		*nb = (*nb * 10) + nptr[i] - '0';
		if (prev_nb > *nb)
			return (false);
		i++;
	}
	return (nptr[i] <= '0' || nptr[i] >= '9' || nptr[i] == '0');
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
