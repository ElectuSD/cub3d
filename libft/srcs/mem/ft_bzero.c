/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:50:08 by fdeleard          #+#    #+#             */
/*   Updated: 2025/05/28 18:56:10 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_mem.h>

/**
 * @brief Set n bytes of pointed memory area to NULL
 *
 * This function sets the first n bytes of memory pointed by s to the value 0
 *
 * @param s Ptr to the memory area to be set to zero
 * @param n Number of bytes to set to zero
 */
void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = s;
	while (n--)
		*ptr++ = '\0';
}
