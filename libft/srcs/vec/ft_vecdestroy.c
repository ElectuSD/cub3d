/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vecdestroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 17:46:35 by fdeleard          #+#    #+#             */
/*   Updated: 2025/05/10 17:49:34 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft_vec.h>

void	ft_vecdestroy(t_vec *vec, void (*del)(void *elem))
{
	if (vec == NULL)
		return ;
	if (del != NULL)
		ft_veciter(vec, del);
	free(vec->content);
	free(vec);
}
