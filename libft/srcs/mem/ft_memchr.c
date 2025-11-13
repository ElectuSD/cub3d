/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:37:07 by fdeleard          #+#    #+#             */
/*   Updated: 2025/05/28 18:56:37 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_mem.h>

/**
 * @brief Locates the first occurrence of a character in a memory block.
 *
 * This function scans the first 'n' bytes of the memory area pointed to by 's'
 * for the first occurrence of the byte 'c'. If 'c' is found, a pointer to the
 * matching byte is returned. If the character is not found, NULL is returned.
 *
 * @param s Pointer to the memory block to be searched.
 * @param c The character to search for, cast to an unsigned char.
 * @param n The number of bytes to search.
 * @return A pointer to the first occurrence of 'c' in 's', 
 *		   or NULL if 'c' is not found.
 */
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)s;
	while (i < n)
	{
		if (ptr[i] == (unsigned char)c)
			return (ptr + i);
		i++;
	}
	return (NULL);
}
