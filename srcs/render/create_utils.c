/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 11:18:47 by fdeleard          #+#    #+#             */
/*   Updated: 2025/08/22 11:28:11 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_render.h"

t_point2d	new_point2d(double x, double y)
{
	t_point2d	new_point;

	new_point.x = x;
	new_point.y = y;
	return (new_point);
}

t_rec	new_rectangle(t_point2d top_left, t_point2d bottom_right)
{
	t_rec	new_rectangle;

	new_rectangle.tl = top_left;
	new_rectangle.br = bottom_right;
	return (new_rectangle);
}
