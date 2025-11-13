/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:44:55 by fdeleard          #+#    #+#             */
/*   Updated: 2025/05/28 18:55:41 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_mem.h>

/**
 * @brief Compares two memory blocks byte by byte.
 *
 * This function compares the first 'n' bytes of the memory areas 's1' and 's2'.
 * It returns an integer less than, equal to, or greater than zero, depending on
 * whether the first byte that does not match has a lower, equal, or greater 
 * value in 's1' than in 's2'.
 *
 * @param s1 Pointer to the first memory block.
 * @param s2 Pointer to the second memory block.
 * @param n The number of bytes to compare.
 * @return An integer indicating the difference between the first unmatched byte:
 *         - A negative value if 's1' is less than 's2'.
 *         - A positive value if 's1' is greater than 's2'.
 *         - Zero if both memory blocks are equal.
 */
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	size_t	delta;

	i = 0;
	while (i < n)
	{
		delta = *(unsigned char *)s1++ - *(unsigned char *)s2++;
		if (delta)
			return (delta);
		i++;
	}
	return (0);
}
