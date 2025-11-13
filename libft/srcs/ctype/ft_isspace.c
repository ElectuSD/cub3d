/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 12:57:07 by fdeleard          #+#    #+#             */
/*   Updated: 2025/02/05 14:06:54 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Checks if a character is a whitespace character.
 *
 * This function checks whether the input character 'c' is considered a 
 * whitespace character.
 * It returns '1' if the character is a space (' '), a horizontal tab (\t), 
 * a newline (\n), a carriage return (\r), a vertical tab (\v), 
 * or a form feed (\f).
 * The function returns '1' if the character is a whitespace character, and '0' 
 * otherwise.
 *
 * @param c The character to be checked.
 * @return 1 if the character is a whitespace character, 0 otherwise.
 */
int	ft_isspace(int c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}
