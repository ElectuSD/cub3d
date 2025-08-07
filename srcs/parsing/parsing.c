/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 10:38:22 by fdeleard          #+#    #+#             */
/*   Updated: 2025/08/07 14:15:49 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_mem.h"
#include "cub3d_map.h"
#include "cub3d_parsing.h"

int	parse_helper(t_parser *parser)
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
	return (MAP_DUPPLICATE);
}

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
	return (NO_ERRORS);
}
