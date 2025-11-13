/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:45:00 by fdeleard          #+#    #+#             */
/*   Updated: 2025/05/28 18:54:23 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_lst.h>

/**
 * @brief Adds a new element at the end of a linked list.
 *
 * This function appends the 'new' element to the end of the linked list 
 * pointed to by 'lst'. If the list is empty, 'new' becomes the first element.
 *
 * @param lst A pointer to the first element of the linked list.
 * @param new The new element to be added at the end of the list.
 */
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	if (*lst)
		ft_lstlast(*lst)->next = new;
	else
		*lst = new;
}
