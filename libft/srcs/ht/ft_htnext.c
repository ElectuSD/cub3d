/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htnext.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 18:28:56 by fdeleard          #+#    #+#             */
/*   Updated: 2025/05/12 18:32:17 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_ht.h>

bool	ft_htnext(t_hti *it)
{
	t_ht		*table;
	size_t		i;
	t_ht_entry	entry;

	table = it->_table;
	while (it->_index < table->capacity)
	{
		i = it->_index;
		it->_index++;
		if (table->entries[i].key != NULL)
		{
			entry = table->entries[i];
			it->key = entry.key;
			it->value = entry.value;
			return (true);
		}
	}
	return (false);
}
