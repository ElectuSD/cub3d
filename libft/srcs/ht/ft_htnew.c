/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htnew.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 16:57:39 by fdeleard          #+#    #+#             */
/*   Updated: 2025/06/16 11:40:45 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_ht.h>
#include <libft_mem.h>

t_ht	*ft_htnew(void)
{
	t_ht	*table;

	table = malloc(sizeof(t_ht));
	if (!table)
		return (NULL);
	table->length = 0;
	table->capacity = INIT_CAPACITY;
	table->entries = ft_calloc(table->capacity, sizeof(t_ht_entry));
	if (!table->entries)
	{
		free(table);
		return (NULL);
	}
	return (table);
}
