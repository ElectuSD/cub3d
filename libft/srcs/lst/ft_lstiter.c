/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:59:17 by fdeleard          #+#    #+#             */
/*   Updated: 2025/05/28 18:55:08 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_lst.h>

/**
 * @brief Applies a function to each element of a linked list.
 *
 * This function iterates through the linked list and applies the function 'f'
 * to the content of each node.
 *
 * @param lst The first node of the linked list.
 * @param f A function to apply to each node's content.
 */
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
