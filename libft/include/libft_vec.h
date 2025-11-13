/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_vec.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 17:24:11 by fdeleard          #+#    #+#             */
/*   Updated: 2025/05/10 17:54:32 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_VEC_H
# define LIBFT_VEC_H

# include <stddef.h>

# define GROWTH_FACTOR 1.5

typedef struct s_vec
{
	void	**content;
	size_t	size;
	size_t	capacity;
}	t_vec;

t_vec	*ft_vecnew(size_t capacity);
t_vec	*ft_vecpush(t_vec *vec, void *item);
t_vec	*ft_vecgrow(t_vec *vec);
t_vec	*ft_vecinsert(t_vec *vec, size_t i, void *item);
void	ft_veciter(t_vec *vec, void (*f)(void *elem));
void	ft_vecdestroy(t_vec *vec, void (*del)(void *elem));

#endif
