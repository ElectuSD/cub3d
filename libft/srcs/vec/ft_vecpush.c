/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vecpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 17:31:34 by fdeleard          #+#    #+#             */
/*   Updated: 2025/05/13 15:49:32 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_vec.h>

t_vec	*ft_vecpush(t_vec *vec, void *item)
{
	if (vec->capacity <= vec->size)
		if (ft_vecgrow(vec) == NULL)
			return (NULL);
	vec->content[vec->size] = item;
	vec->size++;
	return (vec);
}
