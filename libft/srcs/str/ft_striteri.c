/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:57:58 by fdeleard          #+#    #+#             */
/*   Updated: 2025/02/05 14:25:04 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Applies a function to each character of a string.
 *
 * This function iterates through each character of the string 's', 
 * and for each character, it applies the function 'f', 
 * passing the index of the character and a pointer to the character.
 *
 * @param s The string to iterate through.
 * @param f A function that takes an unsigned integer (index) 
 *			and a pointer to a character,
 *          and applies some operation on the character.
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		(*f)(i, &s[i]);
		i++;
	}
}
