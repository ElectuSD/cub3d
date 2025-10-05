/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_ipoint2d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <fdeleard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 02:48:05 by fdeleard          #+#    #+#             */
/*   Updated: 2025/10/05 02:48:17 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_maths.h"

t_ipoint2d	new_ipoint2d(int x, int y)
{
	t_ipoint2d	new_point;

	new_point.x = x;
	new_point.y = y;
	return (new_point);
}
