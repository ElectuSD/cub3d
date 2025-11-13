/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:56:50 by fdeleard          #+#    #+#             */
/*   Updated: 2025/02/05 14:39:08 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Converts a lowercase letter to uppercase.
 *
 * This function takes an integer representing a character and checks if it 
 * corresponds to a lowercase letter (from 'a' to 'z'). If so, it returns 
 * the uppercase equivalent by subtracting 32 from the ASCII value. If the 
 * character is not a lowercase letter, it returns the character unchanged.
 *
 * @param c The character to convert.
 * @return The uppercase equivalent of 'c' if 'c' is a lowercase letter, 
 *         otherwise returns 'c' unchanged.
 */
int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}
