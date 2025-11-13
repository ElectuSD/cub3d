/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprint_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:27:14 by fdeleard          #+#    #+#             */
/*   Updated: 2025/05/28 18:50:59 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <libft_str.h>
#include <ft_printf/ft_printf.h>

int	ft_fprint_char(int c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

int	ft_fprint_str(char *s, int fd)
{
	int	str_len;

	if (!s)
		return (ft_fprint_str("(null)", fd));
	str_len = ft_strlen(s);
	write(fd, s, str_len);
	return (str_len);
}

int	ft_fprint_nbr(int nb, int fd)
{
	int		str_len;
	char	*str;

	str = ft_itoa(nb);
	if (!str)
		return (0);
	str_len = ft_fprint_str(str, fd);
	free(str);
	return (str_len);
}

int	print_format(const char *s, va_list lst_args, int fd)
{
	int	p_len;

	p_len = 0;
	if (s[1] == 'c')
		p_len += ft_fprint_char(va_arg(lst_args, int), fd);
	else if (s[1] == 's')
		p_len += ft_fprint_str(va_arg(lst_args, char *), fd);
	else if (s[1] == 'p')
		p_len += ft_fprint_ptr(va_arg(lst_args, uintptr_t), fd);
	else if (s[1] == 'i' || s[1] == 'd')
		p_len += ft_fprint_nbr(va_arg(lst_args, int), fd);
	else if (s[1] == 'u')
		p_len += ft_fprint_unsigned(va_arg(lst_args, unsigned int), fd);
	else if (s[1] == 'x' || s[1] == 'X')
		p_len += ft_fprint_hex(va_arg(lst_args, unsigned int), s[1], fd);
	else if (s[1] == '%')
		p_len += ft_fprint_char(s[1], fd);
	return (p_len);
}
