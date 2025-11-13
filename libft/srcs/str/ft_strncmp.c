/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:23:11 by fdeleard          #+#    #+#             */
/*   Updated: 2025/05/28 18:57:22 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_str.h>

/**
 * @brief Compares two strings up to a specified number of characters.
 *
 * This function compares the first 'n' characters of the strings 's1' and 's2'.
 * It returns a negative value if the first string is less than the second, a 
 * positive value if the first string is greater than the second, or 0 if the 
 * strings are equal up to the specified length.
 *
 * @param s1 The first string to compare.
 * @param s2 The second string to compare.
 * @param n The number of characters to compare.
 * @return An integer less than, equal to, or greater than zero, depending on 
 *         the comparison of the strings.
 */
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
