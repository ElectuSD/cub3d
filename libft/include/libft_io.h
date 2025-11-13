/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_io.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 15:05:49 by fdeleard          #+#    #+#             */
/*   Updated: 2025/06/05 20:21:56 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_IO_H
# define LIBFT_IO_H

# include <fcntl.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# define MAX_FD 1024

typedef enum e_gnl_flags
{
	GNL_KEEP,
	GNL_FREE,
	GNL_FLUSH,
}	t_gnl_flags;

/* Input Functions */

int		get_next_line(char **line, int fd, t_gnl_flags flag);

/* Output Functions */

void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
int		ft_printf(const char *s, ...);
int		ft_fprintf(int fd, const char *s, ...);

#endif
