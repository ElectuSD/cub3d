/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:27:46 by fdeleard          #+#    #+#             */
/*   Updated: 2025/05/28 18:54:15 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_ctype.h>

/**
 * @brief Checks if a character is alphanumeric (a letter or a digit).
 *
 * This function checks whether the input character 'c' is either 
 * an alphabetic character (A-Z or a-z) or a numeric character (0-9). 
 * The function returns '1' if the character is alphanumeric, 
 * and '0' if it is not.
 *
 * @param c The character to be checked.
 * @return 1 if the character is alphanumeric, 0 otherwise.
 */
int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
