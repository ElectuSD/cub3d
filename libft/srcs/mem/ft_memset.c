/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                     +#+  +:+       +#+		  */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:38:44 by fdeleard           #+#    #+#            */
/*   Updated: 2025/05/28 18:56:45 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_mem.h>

/**
 * @brief Sets 'len' bytes of a memory block to a specified value.
 *
 * This function sets the first 'len' bytes of the memory area pointed to by 'b'
 * to the value of 'c'. The value of 'c' is interpreted as an unsigned char.
 *
 * @param b Pointer to the memory block to be filled.
 * @param c The value to set each byte to, cast to an unsigned char.
 * @param len The number of bytes to set.
 * @return A pointer to the memory block ('b').
 */
void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;

	ptr = (unsigned char *) b;
	while (len > 0)
	{
		*(ptr++) = (unsigned char) c;
		len--;
	}
	return (b);
}
