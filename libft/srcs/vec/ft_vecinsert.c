/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vecinsert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 17:50:09 by fdeleard          #+#    #+#             */
/*   Updated: 2025/05/10 17:54:27 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_vec.h>
#include <libft_mem.h>

t_vec	*ft_vecinsert(t_vec *vec, size_t i, void *item)
{
	if (i > vec->size)
		return (NULL);
	if (vec->capacity <= vec->size)
		if (ft_vecgrow(vec) == NULL)
			return (NULL);
	ft_memmove(vec->content + i + 1, vec->content + i,
		(vec->size - i) * sizeof(void *));
	vec->content[i] = item;
	vec->size++;
	return (vec);
}
