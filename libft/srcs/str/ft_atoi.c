/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:18:13 by fdeleard          #+#    #+#             */
/*   Updated: 2025/06/19 18:11:12 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_str.h>

/**
 * @brief Converts a string into an int
 *
 * This function takes a string as input and tries to convert it into an
 * integer.
 *
 * @param nptr The string to be converted
 * @return The converted string into an integer, 0 if bad input
 */
int	ft_atoi(const char *nptr)
{
	size_t	i;
	size_t	nb;
	size_t	sign;

	i = 0;
	nb = 0;
	sign = 1;
	if (!nptr)
		return (nb);
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb = nb * 10 + nptr[i] - '0';
		i++;
	}
	return (nb * sign);
}
