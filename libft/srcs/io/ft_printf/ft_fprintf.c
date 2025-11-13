/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:27:20 by fdeleard          #+#    #+#             */
/*   Updated: 2025/05/28 18:49:06 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdarg.h>
#include <ft_printf/ft_printf.h>

/**
 * @brief Outputs a formatted string to the specified file descriptor.
 *
 * Mimics the behavior of the standard `fprintf` function. Takes a file
 * descriptor, a format string, and a variable number of arguments. It
 * processes the format string and writes the formatted output to the given
 * file descriptor.
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
 * @param fd The file descriptor to write output to.
 * @param s The format string.
 * @param ... The variable arguments to format.
 * @return The number of characters written (excluding the null-terminator).
 */
int	ft_fprintf(int fd, const char *s, ...)
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
			p_count += print_format(s + (i++), lst_args, fd);
		else if (s[i] != '%')
			p_count += ft_fprint_char(s[i], fd);
		i++;
	}
	va_end(lst_args);
	return (p_count);
}
