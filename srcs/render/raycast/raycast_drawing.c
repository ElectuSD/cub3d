/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_drawing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 10:57:53 by fdeleard          #+#    #+#             */
/*   Updated: 2025/08/29 14:36:43 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_raycast.h"

void	init_raycast_drawing(t_raycast_drawing *rd, t_raycast *r, int x,
			int height)
{
	rd->x = x;
	rd->perp_wall_dist = get_perp_wall_dist(r->v_ray_lenght_1d, \
		r->v_ray_unit_step_size, r->hit_side);
	rd->line_height = height / rd->perp_wall_dist;
	rd->draw_start = -rd->line_height / 2 + height / 2;
	if (rd->draw_start < 0)
		rd->draw_start = 0;
	rd->draw_end = rd->line_height / 2 + height / 2;
	if (rd->draw_end >= height)
		rd->draw_end = height - 1;
}

void	draw_texture_on_img(t_img *img, t_raycast_drawing *rd, t_raycast *r)
{
	int	y;

	y = rd->draw_start;
	set_drawing_textures(img, rd, r);
	while (y < rd->draw_end)
	{
		rd->texture_coord.y = (int)rd->texture_pos % (rd->texture.height);
		rd->texture_pos += rd->step;
		rd->color = get_color_on_img(&rd->texture,
				rd->texture_coord.x, rd->texture_coord.y);
		if (r->hit_side == 1)
			rd->color = (rd->color >> 1) & 8355711;
		draw_pixel(img, rd->x, y, rd->color);
		y++;
	}
}
