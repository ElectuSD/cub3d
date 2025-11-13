/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:37:21 by fdeleard          #+#    #+#             */
/*   Updated: 2025/05/28 18:57:01 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_str.h>
#include <libft_mem.h>

static int	get_size(long nb);
static char	*fill_str(char *str, long nb, size_t size);

/**
 * @brief Converts an integer to a string.
 *
 * This function converts the integer 'n' into its string representation. 
 * It handles both positive and negative integers. If the integer is negative, 
 * the resulting string will include a leading minus sign '-'. 
 * The function allocates memory for the string and returns a pointer to it. 
 * If memory allocation fails, it returns NULL.
 *
 * @param n The integer to be converted to a string.
 * @return A pointer to the resulting string, 
 *		   or NULL if memory allocation fails.
 */
char	*ft_itoa(int n)
{
	char	*str;
	int		size;
	int		sign;
	long	nb;

	nb = n;
	sign = 0;
	if (nb < 0)
	{
		sign = 1;
		nb = -nb;
	}
	size = get_size(n);
	str = ft_calloc(size + sign + 1, sizeof(char));
	if (!str)
		return (NULL);
	if (sign)
		str[0] = '-';
	str = fill_str(str, nb, (size + sign - 1));
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
