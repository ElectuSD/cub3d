/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:55:19 by fdeleard          #+#    #+#             */
/*   Updated: 2025/05/28 18:57:27 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_str.h>

/**
 * @brief Locates a substring within a string, 
 *		  up to a specified number of characters.
 *
 * This function locates the first occurrence of the substring 'little' within 
 * the string 'big', while considering only the first 'n' characters of 'big'.
 * If the substring is found, it returns a pointer to the beginning of the 
 * substring in 'big'. If the substring is not found or the length of 'little' 
 * is zero, the function returns NULL.
 *
 * @param big The string to search within.
 * @param little The substring to search for.
 * @param n The maximum number of characters to search in 'big'.
 * @return A pointer to the first occurrence of 'little' in 'big', or NULL if 
 *         'little' is not found within the first 'n' characters of 'big'.
 */
char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	len_l;

	len_l = ft_strlen(little);
	if (!len_l)
		return ((char *)big);
	i = 0;
	while (i < n && big[i])
	{
		j = 0;
		while ((big[i + j] == little[j]) && (i + j < n) && big[i + j])
			j++;
		if (j == len_l)
			return ((char *)(big + i));
		i++;
	}
	return (NULL);
}
