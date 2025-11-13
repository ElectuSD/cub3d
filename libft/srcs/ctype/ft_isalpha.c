/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:27:46 by fdeleard          #+#    #+#             */
/*   Updated: 2025/02/05 14:05:45 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Checks if a character is alphabetic (a letter).
 *
 * This function checks whether the input character 'c' is an alphabetic 
 * character, meaning it is either an uppercase letter (A-Z) 
 * or a lowercase letter (a-z).
 * The function returns '1' if the character is alphabetic, 
 * and '0' if it is not.
 *
 * @param c The character to be checked.
 * @return 1 if the character is alphabetic, 0 otherwise.
 */
int	ft_isalpha(int c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}
