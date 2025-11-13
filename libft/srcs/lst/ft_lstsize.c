/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:40:01 by fdeleard          #+#    #+#             */
/*   Updated: 2025/05/28 18:54:06 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_lst.h>

/**
 * @brief Counts the number of nodes in a linked list.
 *
 * This function traverses the linked list and returns the total number of nodes.
 *
 * @param lst The first node of the linked list.
 * @return The number of nodes in the list.
 */
int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	if (!lst)
		return (i);
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
