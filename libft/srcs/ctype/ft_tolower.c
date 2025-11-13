/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:03:47 by fdeleard          #+#    #+#             */
/*   Updated: 2025/02/05 14:38:49 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Converts an uppercase letter to lowercase.
 *
 * This function takes an integer representing a character and checks if it 
 * corresponds to an uppercase letter (from 'A' to 'Z'). If so, it returns 
 * the lowercase equivalent by adding 32 to the ASCII value. If the character 
 * is not an uppercase letter, it returns the character unchanged.
 *
 * @param c The character to convert.
 * @return The lowercase equivalent of 'c' if 'c' is an uppercase letter, 
 *         otherwise returns 'c' unchanged.
 */
int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}
