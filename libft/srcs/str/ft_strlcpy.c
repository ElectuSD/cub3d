/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                     +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:42:12 by fdeleard           #+#    #+#            */
/*   Updated: 2025/05/28 18:56:26 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_str.h>
#include <libft_mem.h>

/**
 * @brief Copies a string into another with size limitation.
 *
 * This function copies the string 'src' into 'dst', ensuring that no more than 
 * 'dstsize - 1' characters are written to 'dst'. It always null-terminates 
 * the destination string, provided that 'dstsize' is not zero. The function 
 * returns the length of the string 'src', regardless of how much was copied 
 * to 'dst'.
 *
 * @param dst The destination string to copy to.
 * @param src The source string to copy from.
 * @param dstsize The size of the 'dst' buffer.
 * @return The length of the string 'src'.
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;	

	src_len = ft_strlen(src);
	if (src_len + 1 < dstsize)
		ft_memcpy(dst, src, src_len + 1);
	else if (dstsize != 0)
	{
		ft_memcpy(dst, src, dstsize - 1);
		dst[dstsize - 1] = '\0';
	}
	return (src_len);
}
