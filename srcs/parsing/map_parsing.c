/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 11:13:06 by fdeleard          #+#    #+#             */
/*   Updated: 2025/11/20 11:11:39 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_maths.h"
#include "libft_io.h"
#include "libft_str.h"
#include "libft_lst.h"

#include "cub3d_player.h"
#include "cub3d_parsing.h"

static t_error	add_line_in_map_list(t_parser *parser, char *line);
static bool		check_neighbours(size_t x, size_t y, char **map,
					size_t map_size);

int	parse_map(t_parser *parser)
{
	t_error	error;
	char	*line;

	while (parser->line)
	{
		line = trim_end_of_line(parser->line);
		if (!line)
		{
			free_parser_line(&parser->line);
			return (NO_ERRORS);
		}
		if (!is_valid_map_line(parser, line))
		{
			free_parser_line(&parser->line);
			return (INVALID_MAP_LINE);
		}
		error = add_line_in_map_list(parser, line);
		if (error)
			return (error);
	}
	return (NO_ERRORS);
}

static t_error	add_line_in_map_list(t_parser *parser, char *line)
{
	t_error	error;
	t_list	*new;

	new = ft_lstnew(line);
	if (!new)
	{
		free(line);
		return (MALLOC_ERROR);
	}
	ft_lstadd_back(&parser->map_list, new);
	error = get_next_line(&parser->line, parser->map->fd, GNL_KEEP);
	return (error);
}

char	**convert_list(t_list *map_list)
{
	int		i;
	int		map_size;
	char	**map;
	t_list	*head;

	head = map_list;
	map_size = ft_lstsize(map_list);
	map = malloc((map_size + 1) * sizeof(char *));
	if (!map)
	{
		ft_lstclear(&map_list, free);
		return (NULL);
	}
	i = 0;
	while (i < map_size)
	{
		map[i] = (char *)head->content;
		head = head->next;
		i++;
	}
	ft_lstclear(&map_list, NULL);
	map[map_size] = NULL;
	return (map);
}

bool	map_is_closed(char **map, size_t map_size)
{
	char	cur;
	size_t	line_len;
	size_t	x;
	size_t	y;

	y = 0;
	while (y < map_size)
	{
		line_len = ft_strlen(map[y]);
		x = skip_leading_chars(map[y]) - map[y];
		while (x < line_len)
		{
			cur = map[y][x];
			if (cur == '0' || is_player(cur))
			{
				if (!check_neighbours(x, y, map, map_size))
					return (false);
			}
			x++;
		}
		y++;
	}
	return (true);
}

static bool	check_neighbours(size_t x, size_t y, char **map, size_t map_size)
{
	static int	dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
	static int	dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
	t_ipoint2d	n;
	int			k;
	int			line_len;

	k = 0;
	while (k < 8)
	{
		n.y = y + dy[k];
		n.x = x + dx[k];
		if (n.x < 0 || n.y < 0 || n.y >= (int)map_size)
			return (false);
		line_len = ft_strlen(map[n.y]);
		if (n.x >= line_len)
			return (false);
		else
		{
			if (!is_map_part(map[n.y][n.x]) && map[n.y][n.x] != ' ')
				return (false);
		}
		k++;
	}
	return (true);
}
