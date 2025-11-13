/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 23:32:11 by fdeleard          #+#    #+#             */
/*   Updated: 2025/04/23 20:45:33 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_str.h>
#include <libft_io.h>

/**
 * @brief Writes a string to the specified file descriptor.
 *
 * This function writes the string 's' to the file descriptor 'fd'. 
 * The length of the string is determined by 'ft_strlen' to ensure 
 * the entire string is written.
 *
 * @param s The string to write.
 * @param fd The file descriptor to write the string to.
 */
void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}
