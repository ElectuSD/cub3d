/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:51:03 by fdeleard          #+#    #+#             */
/*   Updated: 2025/05/28 18:41:22 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft_lst.h>

/**
 * @brief Deletes and frees a single node from a linked list.
 *
 * This function frees the memory of the given node’s content using the 
 * provided 'del' function, then frees the node itself.
 *
 * @param lst The node to be deleted.
 * @param del A function used to delete the content of the node.
 */
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst)
		return ;
	if (del)
		del(lst->content);
	free(lst);
}
