/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 10:38:22 by fdeleard          #+#    #+#             */
/*   Updated: 2025/08/06 11:50:35 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "libft_str.h"
#include "libft_io.h"
#include "libft_lst.h"
#include "cub3d_map.h"
#include "cub3d_parsing.h"

static bool	is_empty_line(char *line);
static void	*map_parsing_error(t_list *map, char *error);

char	*skip_leading_whitespaces(char *line)
{
	while (*line == ' ')
		line++;
	return (line);
}

int	parse_helper(t_map *map, char *line)
{
	line = skip_leading_whitespaces(line);
	if (is_texture(line))
	{
	}
	if (is_color(line))
}

int	parse(t_map *map, int fd)
{
	int		error;
	char	*line;

	while (42)
	{
		error = get_next_non_empty_line(&line, fd);
		if (error)
			return (error);
	}
	return (0);
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

int	get_next_non_empty_line(char **line, int fd)
{
	int		error;

	while (42)
	{
		error = get_next_line(line, fd, GNL_KEEP);
		if (error)
			return (error);
		if (!is_empty_line(*line))
			break ;
	}
	return (0);
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

static void	*map_parsing_error(t_list *map, char *error)
{
	ft_lstclear(&map, free);
	printf("Error in map parsing : %s\n", error);
	return (NULL);
}
