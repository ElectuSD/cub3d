/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:35:22 by fdeleard          #+#    #+#             */
/*   Updated: 2025/05/28 18:54:58 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_lst.h>

/**
 * @brief Adds a new element at the beginning of a linked list.
 *
 * This function inserts the 'new' element at the start of the linked list 
 * pointed to by 'lst'. The previous first element becomes the second node.
 *
 * @param lst A pointer to the first element of the linked list.
 * @param new The new element to be added at the beginning of the list.
 */
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
