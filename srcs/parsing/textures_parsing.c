/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_parsing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 11:11:30 by fdeleard          #+#    #+#             */
/*   Updated: 2025/11/13 11:03:33 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_lst.h"
#include "libft_str.h"

#include "cub3d_map.h"
#include "cub3d_parsing.h"

static bool		check_map_parsing(t_parser *parser);
static int		set_texture(bool *has_parsed, char **dir, char *path);
static int		set_texture_helper(t_parser *parser, char *identifier,
					char *path);
static t_error	dup_path(char **path, char *line);

int	parse_textures(t_parser *parser)
{
	int		ret;
	char	*path;
	char	*line;
	char	*identifier;

	if (check_map_parsing(parser))
		return (MAP_NOT_LAST);
	line = ft_strtrim(parser->line, DEFAULT_TRIM);
	if (!line)
		return (MALLOC_ERROR);
	identifier = ft_strtok(line, DEFAULT_TRIM, SKIP_EMPTY);
	path = ft_strtok(NULL, DEFAULT_TRIM, SKIP_EMPTY);
	if (ft_strtok(NULL, DEFAULT_TRIM, SKIP_EMPTY))
	{
		free(line);
		return (INVALID_TEXTURE);
	}
	if (dup_path(&path, line) == MALLOC_ERROR)
		return (MALLOC_ERROR);
	ret = set_texture_helper(parser, identifier, path);
	if (ret && path)
		free(path);
	free(line);
	return (ret);
}

static bool	check_map_parsing(t_parser *parser)
{
	if (parser->parsing_map_done)
	{
		ft_lstclear(&parser->map_list, free);
		return (MAP_NOT_LAST);
	}
	return (NO_ERRORS);
}

static t_error	dup_path(char **path, char *line)
{
	if (*path)
	{
		*path = ft_strdup(*path);
		if (!(*path))
		{
			free(line);
			return (MALLOC_ERROR);
		}
	}
	return (NO_ERRORS);
}

static int	set_texture_helper(t_parser *parser, char *identifier, char *path)
{
	t_map	*map;

	map = parser->map;
	if (is_north(identifier))
	{
		if (set_texture(&parser->n_done, &map->textures.north, path))
			return (NORTH_DUPPLICATE);
	}
	if (is_south(identifier))
	{
		if (set_texture(&parser->s_done, &map->textures.south, path))
			return (SOUTH_DUPPLICATE);
	}
	if (is_west(identifier))
	{
		if (set_texture(&parser->w_done, &map->textures.west, path))
			return (WEST_DUPPLICATE);
	}
	if (is_east(identifier))
	{
		if (set_texture(&parser->e_done, &map->textures.east, path))
			return (EAST_DUPPLICATE);
	}
	return (NO_ERRORS);
}

static int	set_texture(bool *has_parsed, char **dir, char *path)
{
	if (*has_parsed)
		return (PARSE_ERROR);
	*dir = path;
	*has_parsed = true;
	return (NO_ERRORS);
}
