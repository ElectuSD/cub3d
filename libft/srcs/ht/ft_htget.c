/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htget.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 17:49:12 by fdeleard          #+#    #+#             */
/*   Updated: 2025/06/11 03:23:15 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_io.h>
#include <libft_ht.h>
#include <libft_str.h>

static uint64_t	ft_hashkey(const char *key);

void	*ft_htget(t_ht *table, const char *key)
{
	uint64_t	hash;
	size_t		index;

	hash = ft_hashkey(key);
	index = (size_t)(hash & (uint64_t)(table->capacity - 1));
	while (table->entries[index].key != NULL)
	{
		if (ft_strcmp(key, table->entries[index].key) == 0)
			return (table->entries[index].value);
		index++;
		if (index >= table->capacity)
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
