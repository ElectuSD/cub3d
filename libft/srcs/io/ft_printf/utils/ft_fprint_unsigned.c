/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprint_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:43:49 by fdeleard          #+#    #+#             */
/*   Updated: 2025/05/28 18:46:40 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <libft_mem.h>
#include <ft_printf/ft_printf.h>

static char	*ft_itoa_unsigned(unsigned int n);
static char	*fill_str(char *str, long nb, size_t size);
static int	get_size(long nb);

int	ft_fprint_unsigned(unsigned int nb, int fd)
{
	int		str_len;
	char	*str;

	str = ft_itoa_unsigned(nb);
	if (!str)
		return (0);
	str_len = ft_fprint_str(str, fd);
	free(str);
	return (str_len);
}

static char	*ft_itoa_unsigned(unsigned int n)
{
	char			*str;
	int				size;
	unsigned long	nb;

	nb = n;
	size = get_size(n);
	str = ft_calloc(size + 1, sizeof(char));
	if (!str)
		return (NULL);
	str = fill_str(str, nb, (size - 1));
	return (str);
}

static char	*fill_str(char *str, long nb, size_t size)
{
	if (nb == 0)
	{
		str[0] = '0';
		return (str);
	}
	while (nb)
	{
		str[size] = (nb % 10) + '0';
		nb /= 10;
		size--;
	}
	return (str);
}

static int	get_size(long nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}
