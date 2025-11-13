/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 17:58:27 by fdeleard          #+#    #+#             */
/*   Updated: 2025/06/24 11:44:06 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_ht.h>
#include <libft_mem.h>
#include <libft_str.h>

static int			ft_htexpand(t_ht *table);
static uint64_t		ft_hashkey(const char *key);
static const char	*ft_ht_replace_entry(t_ht_entry *entries, size_t capacity,
						size_t *plenght, t_ht_entry new_entry);
static const char	*ft_ht_set_new_entry(t_ht_entry *entries, size_t index,
						t_ht_entry new_entry, size_t *plenght);

const char	*ft_htset(t_ht *table, const char *key, void *value)
{
	t_ht_entry	new_entry;

	if (!value)
		return (NULL);
	if (table->length >= table->capacity / 2)
	{
		if (!ft_htexpand(table))
			return (NULL);
	}
	new_entry.value = value;
	new_entry.key = key;
	return (ft_ht_replace_entry(table->entries, table->capacity, &table->length,
			new_entry));
}

static const char	*ft_ht_replace_entry(t_ht_entry *entries, size_t capacity,
						size_t *plenght, t_ht_entry new_entry)
{
	uint64_t	hash;
	size_t		index;

	hash = ft_hashkey(new_entry.key);
	index = (size_t)(hash & (uint64_t)(capacity - 1));
	while (entries[index].key != NULL)
	{
		if (ft_strcmp(new_entry.key, entries[index].key) == 0)
		{
			entries[index].value = new_entry.value;
			return (entries[index].key);
		}
		if (++index >= capacity)
			index = 0;
	}
	return (ft_ht_set_new_entry(entries, index, new_entry, plenght));
}

static const char	*ft_ht_set_new_entry(t_ht_entry *entries, size_t index,
						t_ht_entry new_entry, size_t *plenght)
{
	if (plenght)
	{
		new_entry.key = ft_strdup(new_entry.key);
		if (!new_entry.key)
			return (NULL);
		(*plenght)++;
	}
	entries[index].key = (char *)new_entry.key;
	entries[index].value = new_entry.value;
	return (new_entry.key);
}

static int	ft_htexpand(t_ht *table)
{
	size_t		i;
	size_t		new_capacity;
	t_ht_entry	entry;
	t_ht_entry	*new_entries;

	new_capacity = table->capacity * 2;
	if (new_capacity < table->capacity)
		return (0);
	new_entries = ft_calloc(new_capacity, sizeof(t_ht_entry));
	if (!new_entries)
		return (0);
	i = 0;
	while (i < table->capacity)
	{
		entry = table->entries[i];
		if (entry.key != NULL)
			ft_ht_replace_entry(new_entries, new_capacity, NULL, entry);
		i++;
	}
	free(table->entries);
	table->entries = new_entries;
	table->capacity = new_capacity;
	return (1);
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
