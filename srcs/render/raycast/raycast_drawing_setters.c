/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_drawing_setters.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 11:20:15 by fdeleard          #+#    #+#             */
/*   Updated: 2025/09/02 19:57:49 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_raycast.h"

void	set_drawing_textures(t_img *img, t_raycast_drawing *rd, t_raycast *r)
{
	rd->texture_coord.x = rd->wall_x * rd->texture.width;
	if (is_east_or_north(r->hit_side, r->raydir))
		rd->texture_coord.x = rd->texture.width - rd->texture_coord.x - 1;
	rd->step = 1.0 * rd->texture.height / rd->line_height;
	rd->texture_pos = (rd->draw_start - (img->height / 2.0)
			+ (rd->line_height / 2.0)) * rd->step;
}
