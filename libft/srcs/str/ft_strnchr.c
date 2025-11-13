/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 13:21:21 by fdeleard          #+#    #+#             */
/*   Updated: 2025/05/14 13:21:35 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_str.h>

/**
 * @brief Locates the first occurrence of a character in a string,
 *        within the first n characters.
 *
 * This function searches for the first occurrence of the character `c`
 * in the first `n` characters of the string `s`.
 *
 * @param s The string to search in.
 * @param c The character to search for, cast to an unsigned char.
 * @param n The maximum number of characters to search.
 * @return A pointer to the first occurrence of `c` in `s`,
 *         or NULL if `c` is not found within the first `n` characters.
 */
char	*ft_strnchr(const char *s, int c, size_t n)
{
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	while (i < n && s[i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}
