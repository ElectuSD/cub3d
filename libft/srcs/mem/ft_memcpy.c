/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:27:35 by fdeleard          #+#    #+#             */
/*   Updated: 2025/05/28 18:54:30 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_mem.h>

/**
 * @brief Copies 'n' bytes from one memory block to another.
 *
 * This function copies 'n' bytes from the memory area 'src' to the memory 
 * area 'dst'.
 * The memory areas must not overlap; use 'ft_memmove' if the memory areas 
 * might overlap.
 * If either 'dst' or 'src' is NULL, the function returns 'dst' without 
 * performing any copy.
 *
 * @param dst Pointer to the destination memory block.
 * @param src Pointer to the source memory block.
 * @param n The number of bytes to copy.
 * @return A pointer to the destination memory block ('dst').
 */
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*tmp_dst;
	unsigned char	*tmp_src;

	if (dst == (void *)0 && src == (void *)0)
		return (dst);
	tmp_dst = (unsigned char *)dst;
	tmp_src = (unsigned char *)src;
	while (n > 0)
	{
		*(tmp_dst++) = *(tmp_src++);
		n--;
	}
	return (dst);
}
