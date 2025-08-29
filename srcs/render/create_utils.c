/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 11:18:47 by fdeleard          #+#    #+#             */
/*   Updated: 2025/08/28 20:03:02 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_render.h"

t_dpoint2d	new_dpoint2d(double x, double y)
{
	t_dpoint2d	new_point;

	new_point.x = x;
	new_point.y = y;
	return (new_point);
}

t_ipoint2d	new_ipoint2d(int x, int y)
{
	t_ipoint2d	new_point;

	new_point.x = x;
	new_point.y = y;
	return (new_point);
}

t_rec	new_rectangle(t_ipoint2d top_left, t_ipoint2d bottom_right)
{
	t_rec	new_rectangle;

	new_rectangle.tl = top_left;
	new_rectangle.br = bottom_right;
	return (new_rectangle);
}
