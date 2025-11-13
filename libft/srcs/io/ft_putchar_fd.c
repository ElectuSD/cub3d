/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 23:30:05 by fdeleard          #+#    #+#             */
/*   Updated: 2025/05/28 18:53:40 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_io.h>

/**
 * @brief Writes a character to the specified file descriptor.
 *
 * This function writes the character 'c' to the file descriptor 'fd'.
 * It uses the 'write' system call to output the character to the given 
 * file descriptor.
 *
 * @param c The character to write.
 * @param fd The file descriptor to write the character to.
 */
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
