/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:43:12 by fdeleard          #+#    #+#             */
/*   Updated: 2025/05/28 18:58:04 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_str.h>

/**
 * @brief Calculates the length of a string.
 *
 * This function counts the number of characters in the string 'str' until it 
 * encounters a null-terminator ('\0'). 
 * It returns the total number of characters in the string, 
 * not including the null-terminator.
 *
 * @param str The string whose length is to be calculated.
 * @return The length of the string 'str'.
 */
size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
