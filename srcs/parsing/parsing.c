/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 10:38:22 by fdeleard          #+#    #+#             */
/*   Updated: 2025/10/02 16:28:29 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_mem.h"
#include "cub3d_map.h"
#include "cub3d_parsing.h"

static int	parse_helper(t_parser *parser);
static int	check_parsing(t_parser *parser);

int	parse(t_map *map)
{
	t_parser	parser;
	int			error;

	ft_memset(&parser, 0, sizeof(t_parser));
	parser.map = map;
	while (42)
	{
		if (!parser.line)
		{
			error = get_next_non_empty_line(&parser.line, map->fd);
			if (error)
				return (error);
			if (!parser.line)
				break ;
		}
		error = parse_helper(&parser);
		if (error)
			return (error);
	}
	map->map = convert_list(parser.map_list);
	if (!map_is_closed(map->map, get_map_size(map->map)))
		return (MAP_NOT_CLOSED);
	error = check_parsing(&parser);
	return (error);
}

static int	parse_helper(t_parser *parser)
{
	int	error;

	if (is_texture(skip_leading_chars(parser->line)))
	{
		error = parse_textures(parser);
		free_parser_line(&parser->line);
		return (error);
	}
	else if (is_color(skip_leading_chars(parser->line)))
	{
		error = parse_colors(parser);
		free_parser_line(&parser->line);
		return (error);
	}
	if (!parser->parsing_map_done)
	{
		error = parse_map(parser);
		parser->parsing_map_done = true;
		return (error);
	}
	free_parser_line(&parser->line);
	return (MAP_DUPPLICATE);
}

static int	check_parsing(t_parser *parser)
{
	if (!parser->c_done || !parser->f_done)
		return (MISSING_COLOR);
	if (!parser->n_done || !parser->s_done
		|| !parser->w_done || !parser->e_done)
		return (MISSING_TEXTURE);
	if (!parser->parsing_map_done)
		return (MISSING_MAP);
	if (!parser->map_infos.has_player)
		return (MISSING_PLAYER);
	return (NO_ERRORS);
}
