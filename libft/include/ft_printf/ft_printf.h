/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:43:57 by fdeleard          #+#    #+#             */
/*   Updated: 2024/12/16 14:52:34 by fdeleard         ###   ########.fr       */
/*   Updated: 2024/12/11 15:59:04 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>

/* Helper function */
int	print_format(const char *s, va_list lst_args, int fd);

/* All print types functions */
int	ft_fprint_nbr(int nb, int fd);
int	ft_fprint_char(int c, int fd);
int	ft_fprint_str(char *s, int fd);
int	ft_fprint_ptr(uintptr_t ptr, int fd);
int	ft_fprint_hex(unsigned int nb, char format, int fd);
int	ft_fprint_unsigned(unsigned int nb, int fd);

#endif
