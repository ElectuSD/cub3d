/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:27:44 by fdeleard          #+#    #+#             */
/*   Updated: 2025/06/16 11:46:03 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_str.h>

/**
 * @brief Extracts a substring from a given string.
 *
 * This function creates a new string that is a substring of the string 's', 
 * starting from the index 'start' and with the length 'len'. If 'start' is 
 * greater than the length of 's', an empty string is returned. If 'len' is 
 * greater than the remaining length of 's' starting from 'start', the function 
 * adjusts 'len' to extract the maximum possible substring.
 *
 * @param s The string to extract the substring from.
 * @param start The starting index of the substring.
 * @param len The maximum length of the substring.
 * @return A new string containing the extracted substring, or NULL if memory 
 *         allocation fails or if the input string 's' is NULL.
 */
char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	str_len;

	if (!s)
		return (NULL);
	str_len = ft_strlen(s);
	if (start > str_len)
		return (ft_strdup(""));
	if (len > str_len - start)
		len = str_len - start;
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len] = '\0';
	i = 0;
	while (i < len)
	{
		str[i] = s[i + start];
		i++;
	}
	return (str);
}
