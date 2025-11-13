/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprint_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:43:30 by fdeleard          #+#    #+#             */
/*   Updated: 2025/05/28 18:41:59 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <libft_io.h>

static void			ft_put_hex(unsigned int nb, char format, int fd);
static unsigned int	ft_put_len(unsigned int nb);

int	ft_fprint_hex(unsigned int nb, char format, int fd)
{
	if (nb == 0)
		return (write(fd, "0", 1));
	else
		ft_put_hex(nb, format, fd);
	return (ft_put_len(nb));
}

static void	ft_put_hex(unsigned int nb, char format, int fd)
{
	if (nb >= 16)
	{
		ft_put_hex(nb / 16, format, fd);
		ft_put_hex(nb % 16, format, fd);
	}
	else
	{
		if (nb <= 9)
			ft_putchar_fd((nb + '0'), fd);
		else
		{
			if (format == 'x')
				ft_putchar_fd((nb - 10 + 'a'), fd);
			if (format == 'X')
				ft_putchar_fd((nb - 10 + 'A'), fd);
		}
	}
}

static unsigned int	ft_put_len(unsigned int nb)
{
	unsigned int	size;

	size = 0;
	while (nb > 0)
	{
		nb /= 16;
		size++;
	}
	return (size);
}
