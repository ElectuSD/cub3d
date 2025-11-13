/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:27:03 by fdeleard          #+#    #+#             */
/*   Updated: 2025/06/16 11:40:58 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_str.h>

/**
 * @brief Applies a function to each character of a string 
 *		  and returns a new string.
 *
 * This function applies the function 'f' to each character of the string 's',
 * passing the index of the character and the character itself to the function. 
 * The result of each function call is stored in a new string, which is then 
 * returned. The new string is null-terminated. If memory allocation fails, 
 * the function returns NULL.
 *
 * @param s The string to iterate over.
 * @param f The function to apply to each character of the string, which takes
 *          an unsigned integer (index) and a character, and returns a 
 *          transformed character.
 * @return A new string with the transformed characters, or NULL if memory 
 *         allocation fails.
 */
char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	s_len;
	unsigned int	i;

	s_len = ft_strlen(s);
	str = malloc((s_len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < s_len)
	{
		str[i] = (*f)(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
