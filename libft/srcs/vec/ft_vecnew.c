/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vecnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 17:28:05 by fdeleard          #+#    #+#             */
/*   Updated: 2025/06/16 11:42:35 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft_vec.h>

t_vec	*ft_vecnew(size_t capacity)
{
	t_vec	*vec;

	vec = malloc(sizeof(t_vec));
	if (!vec)
		return (NULL);
	if (capacity == 0)
		capacity = 1;
	vec->content = malloc(sizeof(void *) * capacity);
	if (!vec->content)
	{
		free(vec);
		return (NULL);
	}
	vec->capacity = capacity;
	vec->size = 0;
	return (vec);
}
