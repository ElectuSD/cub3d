/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 10:38:22 by fdeleard          #+#    #+#             */
/*   Updated: 2025/08/06 14:29:59 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "libft_mem.h"
#include "libft_str.h"
#include "libft_io.h"
#include "libft_lst.h"
#include "cub3d_map.h"
#include "cub3d_colors.h"
#include "cub3d_parsing.h"

static bool	is_empty_line(char *line);

bool	char_in_set(char c, char *set)
{
	while (*set)
	{
		if (c == *set)
			return (true);
		set++;
	}
	return (false);
}

char	*skip_leading_chars(char *line)
{
	while (*line && char_in_set(*line, DEFAULT_TRIM))
		line++;
	return (line);
}

int	set_color_map(bool *has_parsed, t_rgb *map_color, t_rgb *new_color)
{
	if (*has_parsed)
		return (PARSE_ERROR);
	map_color->r = new_color->r;
	map_color->g = new_color->g;
	map_color->b = new_color->b;
	*has_parsed = true;
	return (NO_ERRORS);
}

int	parse_colors(t_parser *parser, char *line)
{
	t_rgb	color;

	color.r = ft_atoi(ft_strtok(NULL, ","));
	color.g = ft_atoi(ft_strtok(NULL, ","));
	color.b = ft_atoi(ft_strtok(NULL, ","));
	if (is_ceiling(line))
		if (set_color_map(&parser->ceiling, &parser->map->ceiling, &color))
			return (CEILING_DUPPLICATE);
	if (is_floor(line))
		if (set_color_map(&parser->floor, &parser->map->floor, &color))
			return (FLOOR_DUPPLICATE);
	return (NO_ERRORS);
}

int	set_texture_path(bool *has_parsed, char **dir, char *path)
{
	if (*has_parsed)
		return (PARSE_ERROR);
	*dir = path;
	*has_parsed = true;
	return (NO_ERRORS);
}

int	parse_textures(t_parser *parser, char *line)
{
	t_map	*map;
	char	*path;

	map = parser->map;
	path = ft_strtok(NULL, DEFAULT_TRIM);
	if (is_north(line))
		if (set_texture_path(&parser->north, &map->textures.north, path))
			return (NORTH_DUPPLICATE);
	if (is_south(line))
		if (set_texture_path(&parser->south, &map->textures.south, path))
			return (SOUTH_DUPPLICATE);
	if (is_west(line))
		if (set_texture_path(&parser->west, &map->textures.west, path))
			return (WEST_DUPPLICATE);
	if (is_east(line))
		if (set_texture_path(&parser->east, &map->textures.east, path))
			return (EAST_DUPPLICATE);
	return (NO_ERRORS);
}

int	parse_helper(t_parser *parser, char *line)
{
	if (is_texture(skip_leading_chars(line)))
	{
		line = ft_strtrim(line, " \t\n");
		if (!line)
			return (MALLOC_ERROR);
		return (parse_textures(parser, line));
	}
	else if (is_color(skip_leading_chars(line)))
	{
		line = ft_strtrim(line, " \t\n");
		if (!line)
			return (MALLOC_ERROR);
		return (parse_colors(parser, line));
	}
	else
	{
	}
	return (NO_ERRORS);
}

int	parse(t_map *map)
{
	t_parser	parser;
	int			error;
	char		*line;

	ft_memset(&parser, 0, sizeof(t_parser));
	parser.map = map;
	while (42)
	{
		error = get_next_non_empty_line(&line, map->fd);
		if (error)
			return (error);
		if (!line)
			break ;
		error = parse_helper(&parser, line);
		free(line);
		if (error)
			return (error);
	}
	return (NO_ERRORS);
}

int	get_next_non_empty_line(char **line, int fd)
{
	int		error;

	while (42)
	{
		error = get_next_line(line, fd, GNL_KEEP);
		if (error)
			return (error);
		if (!is_empty_line(*line) || !(*line))
			break ;
	}
	return (NO_ERRORS);
}

static bool	is_empty_line(char *line)
{
	while (line && *line)
	{
		if (*line != ' ' && *line != '\n')
			return (false);
		line++;
	}
	return (true);
}

/**
static void	*map_parsing_error(t_list *map, char *error)
{
	ft_lstclear(&map, free);
	printf("Error in map parsing : %s\n", error);
	return (NULL);
}

t_list	*map_parsing(int fd)
{
	t_list	*new;
	t_list	*map_list;
	char	*buffer;
	int		error;

	map_list = NULL;
	while (42)
	{
		error = get_next_non_empty_line(&buffer, fd);
		if (error)
			return (map_parsing_error(map_list, strerror(errno)));
		if (!buffer)
			break ;
		new = ft_lstnew(buffer);
		if (!new)
		{
			free(buffer);
			return (map_parsing_error(map_list, strerror(errno)));
		}
		ft_lstadd_back(&map_list, new);
	}
	return (map_list);
}
*/
