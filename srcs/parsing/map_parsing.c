/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 11:13:06 by fdeleard          #+#    #+#             */
/*   Updated: 2025/10/05 04:08:59 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft_io.h"
#include "libft_str.h"
#include "libft_lst.h"

#include "cub3d_player.h"
#include "cub3d_parsing.h"

static bool	check_neighbours(size_t x, size_t y, char **map, size_t map_size);

int	parse_map(t_parser *parser)
{
	char	*line;
	int		error;
	t_list	*new;

	while (parser->line)
	{
		line = trim_end_of_line(parser->line);
		if (!line)
		{
			free_parser_line(&parser->line);
			return (NO_ERRORS);
		}
		if (!is_valid_map_line(parser, line))
			return (INVALID_MAP_LINE);
		new = ft_lstnew(line);
		if (!new)
			return (MALLOC_ERROR);
		ft_lstadd_back(&parser->map_list, new);
		error = get_next_line(&parser->line, parser->map->fd, GNL_KEEP);
		if (error)
			return (error);
	}
	return (NO_ERRORS);
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
		return (NULL);
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
	size_t	x;
	size_t	y;

	y = 0;
	while (y < map_size)
	{
		x = skip_leading_chars(map[y]) - map[y];
		while (x < ft_strlen(map[y]))
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
	int			ny;
	int			nx;
	int			k;

	k = 0;
	while (k < 8)
	{
		ny = y + dy[k];
		nx = x + dx[k];
		if (nx < 0 || ny < 0 || ny >= (int)map_size
			|| nx >= (int)ft_strlen(map[ny]))
			return (false);
		k++;
	}
	return (true);
}
