/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:27:16 by fdeleard          #+#    #+#             */
/*   Updated: 2025/06/16 11:41:09 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_mem.h>

/**
 * @brief Allocate memory for an array of count * size and sets it to 0
 *
 * This function allocates memory of 'count' elements of size 'size' each and
 * then sets all allocated bytes to zero using ft_memset
 * If count * size creates an overflow, the function returns a NULL ptr
 *
 * @param count Number of elements to allocate memory for
 * @param size Size of each element in bytes
 * @return A ptr to the allocated memory, NULL if the allocation fails or
 *		   an overflow occurs
 */
void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*ptr;
	long long		buffer;

	buffer = count * size;
	if (size != 0 && (count != buffer / size))
		return (NULL);
	ptr = malloc(buffer);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, buffer);
	return (ptr);
}
