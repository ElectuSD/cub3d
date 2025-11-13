/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 13:00:50 by fdeleard          #+#    #+#             */
/*   Updated: 2025/05/28 18:40:10 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/**
 * @brief Frees the memory allocated for any array of pointers
 *
 * This Function takes a pointer to an array of pointers and frees each elements
 * in the array, as well as the array itself.
 * The array and its elements must have been dynamically allocated and must be
 * NULL terminated
 * Does nothing if input is NULL
 *
 * @param tab A pointer to the array of pointer to be freed
 */

void	ft_free_tab(void **tab)
{
	int	i;

	if (tab == NULL)
		return ;
	i = 0;
	while (tab[i])
	{
		if (tab[i])
		{
			free(tab[i]);
			tab[i] = NULL;
		}
		i++;
	}
	free(tab);
	tab = NULL;
}
