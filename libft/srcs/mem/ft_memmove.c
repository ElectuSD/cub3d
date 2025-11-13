/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:07:47 by fdeleard          #+#    #+#             */
/*   Updated: 2025/06/19 16:54:11 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_mem.h>

/**
 * @brief Safely copies 'n' bytes from one memory block to another, 
 * handling overlapping memory.
 *
 * This function copies 'n' bytes from the memory area 'src' to the memory area 
 * 'dest'.
 * Unlike 'ft_memcpy', 'ft_memmove' handles the case when the memory areas 
 * overlap by copying 
 * the bytes in a safe manner, depending on the relative positions of 'dest' 
 * and 'src'.
 * If either 'dest' or 'src' is NULL, the function returns NULL without 
 * performing any copy.
 *
 * @param dest Pointer to the destination memory block.
 * @param src Pointer to the source memory block.
 * @param n The number of bytes to copy.
 * @return A pointer to the destination memory block ('dest').
 */
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int	i;

	if (!dest || !src)
		return (NULL);
	if (dest < src)
	{
		i = 0;
		while ((size_t)i < n)
		{
			*(unsigned char *)(dest + i) = *(unsigned char *)(src + i);
			i++;
		}
	}
	else
	{
		i = n - 1;
		while (i >= 0)
		{
			*(unsigned char *)(dest + i) = *(unsigned char *)(src + i);
			i--;
		}
	}
	return (dest);
}
