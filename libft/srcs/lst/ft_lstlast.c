/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:43:19 by fdeleard          #+#    #+#             */
/*   Updated: 2025/05/28 18:41:40 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft_lst.h>

/**
 * @brief Returns the last node of a linked list.
 *
 * This function iterates through the linked list and returns the last node.
 * If the list is empty, it returns NULL.
 *
 * @param lst The first node of the linked list.
 * @return The last node of the list, or NULL if the list is empty.
 */
t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
