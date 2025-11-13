/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:32:52 by fdeleard          #+#    #+#             */
/*   Updated: 2025/05/28 18:46:12 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <ft_printf/ft_printf.h>

/**
 * @brief Outputs a formatted string to standard output.
 *
 * This function is a simplified implementation of the printf family of 
 * functions. It takes a format string and a variable number of arguments. 
 * It processes the format string and prints the corresponding output based 
 * on the format specifiers in the string.
 *
 * Supported format specifiers:
 * - %c: Prints a character.
 * - %s: Prints a string.
 * - %p: Prints a pointer address.
 * - %i, %d: Prints a signed integer.
 * - %u: Prints an unsigned integer.
 * - %x, %X: Prints a hexadecimal representation of an unsigned integer.
 * - %%: Prints a literal percent sign.
 *
 * @param s The format string.
 * @return The number of characters printed (excluding the null-terminator).
 */
int	ft_printf(const char *s, ...)
{
	int		i;
	size_t	p_count;
	va_list	lst_args;

	i = 0;
	p_count = 0;
	va_start(lst_args, s);
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1] != '\0')
			p_count += print_format(s + (i++), lst_args, 1);
		else if (s[i] != '%')
			p_count += ft_fprint_char(s[i], 1);
		i++;
	}
	va_end(lst_args);
	return (p_count);
}
