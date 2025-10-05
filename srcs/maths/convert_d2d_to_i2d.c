/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_d2d_to_i2d.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <fdeleard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 02:49:37 by fdeleard          #+#    #+#             */
/*   Updated: 2025/10/05 02:50:31 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_maths.h"

t_ipoint2d	convert_dpoint2d_to_ipoint2d(t_dpoint2d dpoint2d)
{
	t_ipoint2d	new;

	new = new_ipoint2d(dpoint2d.x, dpoint2d.y);
	return (new);
}
