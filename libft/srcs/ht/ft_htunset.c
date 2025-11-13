/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htunset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 11:28:19 by fdeleard          #+#    #+#             */
/*   Updated: 2025/05/16 11:38:13 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_ht.h>
#include <libft_str.h>

static uint64_t	ft_hashkey(const char *key);

const char	*ft_htunset(t_ht *table, const char *key, void (*del)(void *))
{
	uint64_t	hash;
	size_t		index;

	if (!key)
		return (NULL);
	hash = ft_hashkey(key);
	index = (size_t)(hash & (uint64_t)(table->capacity - 1));
	while (table->entries[index].key != NULL)
	{
		if (ft_strcmp(key, table->entries[index].key) == 0)
		{
			if (del)
				del(table->entries[index].value);
			table->entries[index].value = NULL;
			return (table->entries[index].key);
		}
		if (++index >= table->capacity)
			index = 0;
	}
	return (NULL);
}

#define FNV_OFFSET 14695981039346656037UL
#define FNV_PRIME 1099511628211UL

static uint64_t	ft_hashkey(const char *key)
{
	uint64_t	hash;
	const char	*p;

	hash = FNV_OFFSET;
	p = key;
	while (*p)
	{
		hash ^= (uint64_t)(unsigned char)(*p);
		hash *= FNV_PRIME;
		p++;
	}
	return (hash);
}
