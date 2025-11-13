/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 23:35:03 by fdeleard          #+#    #+#             */
/*   Updated: 2025/05/28 18:49:56 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <libft_str.h>

/**
 * @brief Writes a string followed by a newline to the specified file descriptor.
 *
 * This function writes the string 's' to the file descriptor 'fd', 
 * followed by a newline character.
 * The length of the string is determined by 'ft_strlen' 
 * and the newline is added after the string.
 *
 * @param s The string to write.
 * @param fd The file descriptor to write the string to.
 */
void	ft_putendl_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}
