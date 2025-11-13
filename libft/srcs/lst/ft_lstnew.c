/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:31:38 by fdeleard          #+#    #+#             */
/*   Updated: 2025/06/16 11:42:50 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft_lst.h>

/**
 * @brief Creates a new linked list node.
 *
 * This function allocates memory for a new node, initializes its content with 
 * the given value, and sets the next pointer to NULL.
 *
 * @param content The content to store in the new node.
 * @return A pointer to the new node, or NULL if memory allocation fails.
 */
t_list	*ft_lstnew(void *content)
{
	t_list	*lstnew;

	lstnew = malloc(sizeof(t_list));
	if (!lstnew)
		return (NULL);
	lstnew->content = content;
	lstnew->next = NULL;
	return (lstnew);
}
