/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_drawing_getters.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 11:22:24 by fdeleard          #+#    #+#             */
/*   Updated: 2025/08/29 11:22:52 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "cub3d_map.h"
#include "cub3d_raycast.h"

void	get_wall_texture(t_map *map, t_raycast *r, t_raycast_drawing *rd)
{
	if (r->hit_side == 0)
	{
		if (r->v_ray_dir.x > 0)
			rd->texture = map->textures.e;
		else
			rd->texture = map->textures.w;
		rd->wall_x = map->player.pos.y + rd->perp_wall_dist * r->v_ray_dir.y;
	}
	else
	{
		if (r->v_ray_dir.y > 0)
			rd->texture = map->textures.s;
		else
			rd->texture = map->textures.n;
		rd->wall_x = map->player.pos.x + rd->perp_wall_dist * r->v_ray_dir.x;
	}
	rd->wall_x -= floor(rd->wall_x);
}
