/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_rectangle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <fdeleard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 02:48:22 by fdeleard          #+#    #+#             */
/*   Updated: 2025/10/05 02:49:18 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_maths.h"

t_rec	new_rectangle(t_ipoint2d top_left, t_ipoint2d bottom_right)
{
	t_rec	new_rectangle;

	new_rectangle.tl = top_left;
	new_rectangle.br = bottom_right;
	return (new_rectangle);
}
