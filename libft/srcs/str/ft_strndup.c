/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:20:41 by fdeleard          #+#    #+#             */
/*   Updated: 2025/06/16 11:43:46 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_str.h>

/**
 * @brief Duplicates at most `size` characters from the input string.
 *
 * This function allocates a new null-terminated string and copies up to
 * `size` characters from the beginning of `str` into it. If `str` is shorter
 * than `size`, the resulting string will contain only the characters up to
 * the null terminator. The result is always null-terminated.
 *
 * @param str The input string to duplicate from.
 * @param size The maximum number of characters to duplicate.
 *
 * @return A newly allocated null-terminated string containing up to `size`
 * characters from `str`, or NULL if memory allocation fails or if `size` is 0.
 *
 * @note If `str` is NULL, this function may cause undefined behavior
 * unless checked before calling.
 */
char	*ft_strndup(const char *str, size_t size)
{
	size_t	i;
	char	*new_str;

	new_str = malloc(sizeof(char) * (size + 1));
	if (!new_str)
		return (NULL);
	i = 0;
	while (str[i] && i < size)
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
