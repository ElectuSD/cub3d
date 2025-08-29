/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_getters.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 11:04:22 by fdeleard          #+#    #+#             */
/*   Updated: 2025/08/29 11:04:45 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "cub3d_render.h"

double	get_perp_wall_dist(t_dpoint2d v_ray_lenght_1d,
			t_dpoint2d v_ray_unit_step_size, int side)
{
	if (side == 0)
		return (v_ray_lenght_1d.x - v_ray_unit_step_size.x);
	return (v_ray_lenght_1d.y - v_ray_unit_step_size.y);
}

t_dpoint2d	get_ray_dir(t_dpoint2d dir, t_dpoint2d plane, double camerax)
{
	return (new_dpoint2d(dir.x + plane.x * camerax, dir.y + plane.y * camerax));
}

t_dpoint2d	get_ray_unit_step_size(t_dpoint2d v_ray_dir)
{
	t_dpoint2d	v_ray_unit_step_size;

	if (v_ray_dir.x == 0)
		v_ray_unit_step_size.x = 1e30;
	else
		v_ray_unit_step_size.x = fabs(1 / v_ray_dir.x);
	if (v_ray_dir.y == 0)
		v_ray_unit_step_size.y = 1e30;
	else
		v_ray_unit_step_size.y = fabs(1 / v_ray_dir.y);
	return (v_ray_unit_step_size);
}
