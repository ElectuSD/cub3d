/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_ht.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 16:55:02 by fdeleard          #+#    #+#             */
/*   Updated: 2025/06/24 11:45:11 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_HT_H
# define LIBFT_HT_H

# include <stddef.h>
# include <stdint.h>
# include <stdbool.h>
# include <libft_lst.h>

# define INIT_CAPACITY 64
# define TOMBSTONE "\001"

typedef struct s_ht_entry
{
	const char	*key;
	void		*value;
}	t_ht_entry;

typedef struct s_ht
{
	t_ht_entry	*entries;
	size_t		capacity;
	size_t		length;
}	t_ht;

typedef struct s_hti
{
	const char	*key;
	void		*value;
	t_ht		*_table;
	size_t		_index;
}	t_hti;

/* Hash Tables creation/destruction functions */
t_ht			*ft_htnew(void);
void			ft_htdestroy(t_ht **table);

/* Get and set value in Hash Table */
void			*ft_htget(t_ht *table, const char *key);
const char		*ft_htset(t_ht *table, const char *key, void *value);
const char		*ft_htunset(t_ht *table, const char *key, void (*del)(void *));

/* Utils Functions */
size_t			ft_htlenght(t_ht *table);
t_hti			ft_htiterator(t_ht *table);
bool			ft_htnext(t_hti *it);

#endif
