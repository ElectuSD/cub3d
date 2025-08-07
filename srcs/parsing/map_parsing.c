/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 11:13:06 by fdeleard          #+#    #+#             */
/*   Updated: 2025/08/07 14:17:24 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft_io.h"
#include "libft_lst.h"

#include "cub3d_parsing.h"

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
		if (!is_valid_map_line(&parser->map_infos, line))
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
