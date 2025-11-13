/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:11:00 by fdeleard          #+#    #+#             */
/*   Updated: 2025/06/16 11:41:43 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft_io.h>
#include <libft_str.h>

static char	*parse_line(char *line);
static void	clear_gnl(char **previous, int fd, t_gnl_flags flag);
static int	read_file(char **line, int fd, char **previous, char *buffer);

/**
 * @brief Reads the next line from a file descriptor.
 *
 * This function reads the next line from the file associated with the 
 * given file descriptor (@p fd). The line is stored in the memory pointed 
 * to by @p line. It uses a static buffer to manage leftover data across 
 * multiple calls. If @p clear_prev is set to 1, the function clears any 
 * remaining buffer after reading a line.
 *
 * @param line Pointer to a char pointer where the read line will be stored.
 *             The memory is dynamically allocated and must be freed.
 * @param fd The file descriptor to read from.
 * @param clear_prev A flag indicating whether to clear the remaining buffer
 *                   after reading the line (1 = clear, 0 = retain).
 * @return 0 on success,
 *         1 if an invalid file descriptor or buffer size is detected,
 *         2 on memory allocation or read failure.
 */
int	get_next_line(char **line, int fd, t_gnl_flags flag)
{
	static char	*previous[MAX_FD];
	char		buffer[BUFFER_SIZE + 1];
	int			status;

	if (fd >= MAX_FD || fd < 0 || BUFFER_SIZE <= 0)
		return (1);
	if (!line)
	{
		clear_gnl(previous, fd, flag);
		return (0);
	}
	status = read_file(line, fd, &previous[fd], buffer);
	if (status)
		return (status);
	previous[fd] = parse_line(*line);
	clear_gnl(previous, fd, flag);
	return (0);
}

static char	*parse_line(char *line)
{
	char	*previous;
	size_t	i;

	i = 0;
	if (!line)
		return (NULL);
	while (line[i] != '\n' && line[i])
		i++;
	if (line[i] == '\0')
		return (NULL);
	previous = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (previous && *previous == '\0')
	{
		free(previous);
		previous = NULL;
		return (NULL);
	}
	line[i + 1] = '\0';
	return (previous);
}

static int	read_file(char **line, int fd, char **previous, char *buffer)
{
	ssize_t	b_read;

	b_read = 1;
	while (b_read > 0)
	{
		b_read = read(fd, buffer, BUFFER_SIZE);
		if (b_read == -1)
		{
			free(*previous);
			*previous = NULL;
			return (1);
		}
		if (b_read == 0)
			break ;
		buffer[b_read] = '\0';
		*previous = ft_strjoin_free(*previous, buffer, FREE_S1);
		if (!(*previous))
			return (2);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	*line = *previous;
	return (0);
}

static void	clear_gnl(char **previous, int fd, t_gnl_flags flag)
{
	int	i;

	if (flag == GNL_FREE)
	{
		if (previous[fd])
		{
			free(previous[fd]);
			previous[fd] = NULL;
		}
	}
	if (flag == GNL_FLUSH)
	{
		i = 0;
		while (i < MAX_FD)
		{
			if (previous[i])
			{
				free(previous[i]);
				previous[i] = NULL;
			}
			i++;
		}
	}
}
