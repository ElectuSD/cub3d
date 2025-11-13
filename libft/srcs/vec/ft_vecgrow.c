/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vecgrow.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 17:34:22 by fdeleard          #+#    #+#             */
/*   Updated: 2025/06/16 11:44:03 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft_mem.h>
#include <libft_vec.h>

t_vec	*ft_vecgrow(t_vec *vec)
{
	size_t	new_capacity;
	void	**new_content;

	if (vec->capacity <= 1)
		new_capacity = 2;
	else
		new_capacity = vec->capacity * GROWTH_FACTOR;
	new_content = malloc(sizeof(void *) * new_capacity);
	if (!new_content)
		return (NULL);
	ft_memcpy(new_content, vec->content, vec->size * sizeof(void *));
	free(vec->content);
	vec->content = new_content;
	vec->capacity = new_capacity;
	return (vec);
}
