/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_dpoint2d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <fdeleard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 02:47:24 by fdeleard          #+#    #+#             */
/*   Updated: 2025/10/05 02:48:17 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_maths.h"

t_dpoint2d	new_dpoint2d(double x, double y)
{
	t_dpoint2d	new_point;

	new_point.x = x;
	new_point.y = y;
	return (new_point);
}
