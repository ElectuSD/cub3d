/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:02:49 by fdeleard          #+#    #+#             */
/*   Updated: 2025/05/28 18:51:42 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft_lst.h>

/**
 * @brief Creates a new linked list by applying a function to each element.
 *
 * This function applies the function 'f' to the content of each node in the
 * given list and creates a new list with the results. If memory allocation 
 * fails, the function clears the new list using 'del' and returns NULL.
 *
 * @param lst The first node of the original linked list.
 * @param f A function to apply to each node's content.
 * @param del A function to delete the content in case of memory failure.
 * @return A new linked list with modified content, or NULL if allocation fails.
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	void	*content;
	t_list	*head;
	t_list	*new;

	if (!lst || !f)
		return (NULL);
	head = NULL;
	while (lst)
	{
		content = f(lst->content);
		new = ft_lstnew(content);
		if (!new)
		{
			ft_lstclear(&head, del);
			del(content);
			return (NULL);
		}
		ft_lstadd_back(&head, new);
		lst = lst->next;
	}
	return (head);
}
