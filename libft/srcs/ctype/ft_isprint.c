/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:27:46 by fdeleard          #+#    #+#             */
/*   Updated: 2025/02/05 14:06:54 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Checks if a character is printable.
 *
 * This function checks whether the input character 'c' is a 
 * printable character.
 * Printable characters are those with ASCII values in the range from 
 * 32 (space) to 126 (tilde ~),
 * which includes letters, digits, punctuation, and spaces.
 * The function returns '1' if the character is printable, and '0' otherwise.
 *
 * @param c The character to be checked.
 * @return 1 if the character is printable (ASCII values 32-126), 0 otherwise.
 */
int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}
