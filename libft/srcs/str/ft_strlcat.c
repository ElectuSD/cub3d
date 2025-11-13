/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                     +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:42:12 by fdeleard           #+#    #+#            */
/*   Updated: 2025/05/28 18:57:16 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_str.h>
#include <libft_mem.h>

/**
 * @brief Appends a string to another with size limitation.
 *
 * This function appends the string 'src' to the string 'dst', but ensures 
 * that no more than 'dstsize - 1' characters are written to 'dst', leaving 
 * space for the null-terminator. The function always null-terminates the 
 * resulting string. It returns the total length of the string that would 
 * have been created if there were unlimited space (i.e., the sum of the 
 * lengths of 'src' and 'dst').
 *
 * @param dst The destination string to append to.
 * @param src The source string to append.
 * @param dstsize The size of the 'dst' buffer.
 * @return The total length of the string that would have been created if 
 *         enough space was available.
 */
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;	
	size_t	dst_len;

	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	if (dst_len >= dstsize)
		return (dstsize + src_len);
	if (src_len < dstsize - dst_len - 1)
		ft_memcpy(dst + dst_len, src, src_len + 1);
	else
	{
		ft_memcpy(dst + dst_len, src, dstsize - dst_len - 1);
		dst[dstsize - 1] = '\0';
	}
	return (dst_len + src_len);
}
