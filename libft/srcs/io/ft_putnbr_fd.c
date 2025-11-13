/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 23:41:47 by fdeleard          #+#    #+#             */
/*   Updated: 2025/05/28 18:53:28 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_io.h>

/**
 * @brief Writes an integer to the specified file descriptor.
 *
 * This function writes the integer 'n' to the file descriptor 'fd'. 
 * If the integer is negative, it first writes a minus sign. 
 * It handles both positive and negative integers and recursively
 * outputs the digits to the specified file descriptor.
 *
 * @param n The integer to write.
 * @param fd The file descriptor to write the integer to.
 */
void	ft_putnbr_fd(int n, int fd)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb = -nb;
	}
	if (nb > 9)
	{
		ft_putnbr_fd(nb / 10, fd);
		ft_putnbr_fd(nb % 10, fd);
	}
	if (nb <= 9)
		ft_putchar_fd(nb + 48, fd);
}
