/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 11:15:42 by fdeleard          #+#    #+#             */
/*   Updated: 2025/08/25 20:19:06 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft_str.h"
#include "libft_io.h"
#include "libft_utils.h"

#include "cub3d_parsing.h"

static bool	is_empty_line(char *line);

void	free_parser_line(char **line)
{
	if (line && *line)
	{
		free(*line);
		*line = NULL;
	}
}

char	*skip_leading_chars(char *line)
{
	while (*line && char_in_set(*line, DEFAULT_TRIM))
		line++;
	return (line);
}

char	*trim_end_of_line(char *line)
{
	int	size_of_line;

	if (!line)
		return (NULL);
	size_of_line = ft_strlen(line) - 1;
	while (size_of_line >= 0 && char_in_set(line[size_of_line], DEFAULT_TRIM))
	{
		line[size_of_line] = '\0';
		size_of_line--;
	}
	if (line && line[0] == '\0')
		return (NULL);
	return (line);
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
		free(*line);
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
