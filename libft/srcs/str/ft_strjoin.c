/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                     +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 12:16:17 by fdeleard           #+#    #+#            */
/*   Updated: 2025/06/16 11:42:20 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_str.h>

/**
 * @brief Joins two strings into a new string.
 *
 * This function allocates memory for a new string and concatenates 
 * the strings 's1' and 's2'.
 * The new string is formed by appending 's2' to the end of 's1'. 
 * The result is null-terminated.
 * If memory allocation fails, the function returns NULL.
 *
 * @param s1 The first string to join.
 * @param s2 The second string to join.
 * @return A pointer to the newly allocated string containing 
 *		  's1' followed by 's2' or NULL if memory allocation fails.
 */
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		str[j++] = s1[i++];
	i = 0;
	while (s2[i])
		str[j++] = s2[i++];
	str[j] = '\0';
	return (str);
}
