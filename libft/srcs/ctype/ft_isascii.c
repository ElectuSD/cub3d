/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:27:46 by fdeleard          #+#    #+#             */
/*   Updated: 2025/02/05 14:06:54 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Checks if a character is an ASCII character.
 *
 * This function checks whether the input character 'c' is a valid ASCII 
 * character.
 * ASCII characters are in the range of 0 to 127 (inclusive).
 * The function returns '1' if the character is an ASCII character, and '0' 
 * otherwise.
 *
 * @param c The character to be checked.
 * @return 1 if the character is an ASCII character, 0 otherwise.
 */
int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
