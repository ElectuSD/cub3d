/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htdestroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 17:41:25 by fdeleard          #+#    #+#             */
/*   Updated: 2025/05/28 18:40:58 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft_ht.h>

void	ft_htdestroy(t_ht **table)
{
	size_t	i;

	if (!(*table))
		return ;
	i = 0;
	while (i < (*table)->capacity)
	{
		if ((*table)->entries)
		{
			free((void *)(*table)->entries[i].key);
			free((void *)(*table)->entries[i].value);
			(*table)->entries[i].key = NULL;
			(*table)->entries[i].value = NULL;
		}
		i++;
	}
	free((*table)->entries);
	(*table)->entries = NULL;
	free((*table));
	(*table) = NULL;
}
