/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:27:46 by fdeleard          #+#    #+#             */
/*   Updated: 2025/02/05 14:06:54 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Checks if a character is a digit (0-9).
 *
 * This function checks whether the input character 'c' is a numeric digit,
 * which includes the characters '0' through '9'.
 * The function returns '1' if the character is a digit, and '0' otherwise.
 *
 * @param c The character to be checked.
 * @return 1 if the character is a digit (0-9), 0 otherwise.
 */
int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
