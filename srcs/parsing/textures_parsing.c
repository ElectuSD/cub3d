/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_parsing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 11:11:30 by fdeleard          #+#    #+#             */
/*   Updated: 2025/08/07 14:24:38 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_str.h"

#include "cub3d_map.h"
#include "cub3d_parsing.h"

static int	set_texture_path(bool *has_parsed, char **dir, char *path);

int	parse_textures(t_parser *parser)
{
	char	*line;
	t_map	*map;
	char	*identifier;
	char	*path;

	map = parser->map;
	line = ft_strtrim(parser->line, DEFAULT_TRIM);
	if (!line)
		return (MALLOC_ERROR);
	identifier = ft_strtok(line, DEFAULT_TRIM);
	path = ft_strtok(NULL, DEFAULT_TRIM);
	if (is_north(identifier))
		if (set_texture_path(&parser->north_done, &map->textures.north, path))
			return (NORTH_DUPPLICATE);
	if (is_south(identifier))
		if (set_texture_path(&parser->south_done, &map->textures.south, path))
			return (SOUTH_DUPPLICATE);
	if (is_west(identifier))
		if (set_texture_path(&parser->west_done, &map->textures.west, path))
			return (WEST_DUPPLICATE);
	if (is_east(identifier))
		if (set_texture_path(&parser->east_done, &map->textures.east, path))
			return (EAST_DUPPLICATE);
	return (NO_ERRORS);
}

static int	set_texture_path(bool *has_parsed, char **dir, char *path)
{
	if (*has_parsed)
		return (PARSE_ERROR);
	*dir = path;
	*has_parsed = true;
	return (NO_ERRORS);
}
