/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:05:58 by fdeleard          #+#    #+#             */
/*   Updated: 2025/05/28 18:56:51 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_str.h>

/**
 * @brief Locates the last occurrence of a character in a string.
 *
 * This function searches for the last occurrence of the character 'c' in the 
 * string 's'. If the character is found, it returns a pointer to the last 
 * occurrence of 'c'. If 'c' is not found, the function returns NULL.
 *
 * @param s The string to search within.
 * @param c The character to search for.
 * @return A pointer to the last occurrence of 'c' in 's', or NULL if 'c' is 
 *         not found in the string.
 */
char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			break ;
		i--;
	}
	if (s[i] == (char)c)
		return ((char *)s + i);
	return (NULL);
}
