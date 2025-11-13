/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:54:30 by fdeleard          #+#    #+#             */
/*   Updated: 2025/08/07 11:24:25 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft_lst.h>

/**
 * @brief Deletes and frees an entire linked list.
 *
 * This function deletes and frees each node in the linked list pointed to 
 * by 'lst', using the provided 'del' function to free the content. The 
 * pointer to the list is set to NULL after the operation.
 *
 * @param lst A pointer to the first element of the linked list.
 * @param del A function used to delete the content of each node.
 */
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	if (!lst || !(*lst))
		return ;
	if ((*lst)->next)
		ft_lstclear(&(*lst)->next, del);
	if (del)
		del((*lst)->content);
	free(*lst);
	*lst = NULL;
}
