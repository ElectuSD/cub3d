/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:27:25 by fdeleard          #+#    #+#             */
/*   Updated: 2025/06/16 11:41:21 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_str.h>

/**
 * @brief Duplicates a string by allocating memory for a new string.
 *
 * This function allocates memory for a new string and copies the content 
 * of the string 's1' into the newly allocated memory. 
 * The new string is null-terminated. If memory allocation fails,
 * the function returns NULL.
 *
 * @param s1 The string to duplicate.
 * @return A pointer to the newly allocated string, 
 *		   or NULL if memory allocation fails.
 */
char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	i;

	s2 = malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!s2)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
