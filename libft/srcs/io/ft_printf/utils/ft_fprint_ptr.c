/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprint_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:20:34 by fdeleard          #+#    #+#             */
/*   Updated: 2025/05/28 18:50:36 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <libft_io.h>
#include <ft_printf/ft_printf.h>

static void	ft_put_ptr(uintptr_t ptr, int fd);
static int	ft_put_len(uintptr_t ptr);

int	ft_fprint_ptr(uintptr_t ptr, int fd)
{
	int	p_count;

	p_count = 0;
	if (ptr == 0)
		return (write(fd, "(nil)", 5));
	p_count += write(fd, "0x", 2);
	ft_put_ptr(ptr, fd);
	p_count += ft_put_len(ptr);
	return (p_count);
}

static void	ft_put_ptr(uintptr_t ptr, int fd)
{
	if (ptr >= 16)
	{
		ft_put_ptr(ptr / 16, fd);
		ft_put_ptr(ptr % 16, fd);
	}
	else
	{
		if (ptr <= 9)
			ft_putchar_fd((ptr + '0'), fd);
		else
			ft_putchar_fd((ptr - 10 + 'a'), fd);
	}
}

static int	ft_put_len(uintptr_t ptr)
{
	int	size;

	size = 0;
	while (ptr != 0)
	{
		ptr /= 16;
		size++;
	}
	return (size);
}
