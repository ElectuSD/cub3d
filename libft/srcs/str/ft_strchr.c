/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:05:58 by fdeleard          #+#    #+#             */
/*   Updated: 2025/05/28 18:58:18 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_str.h>

/**
 * @brief Locates the first occurrence of a character in a string.
 *
 * This function searches for the first occurrence of the character 'c' 
 * in the string 's'.
 * If the character is found, it returns a pointer to the first occurrence
 * in the string.
 * If the character is not found, it returns NULL.
 *
 * @param s The string to search in.
 * @param c The character to search for, cast to an unsigned char.
 * @return A pointer to the first occurrence of 'c' in 's', 
 *		   or NULL if 'c' is not found.
 */
char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			break ;
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)s + i);
	return (NULL);
}
