/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 13:48:17 by fdeleard          #+#    #+#             */
/*   Updated: 2025/08/29 13:48:41 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_map.h"
#include "cub3d_render.h"

void	draw_player(t_img *img, t_map *map)
{
	draw_rectangle_fill(img,
		new_ipoint2d((map->player.pos.x - 0.25) * img->scale,
			(map->player.pos.y - 0.25) * img->scale),
		new_ipoint2d((map->player.pos.x + 0.25) * img->scale,
			(map->player.pos.y + 0.25) * img->scale), 0xFF0000);
	draw_line(img,
		new_ipoint2d(map->player.pos.x * img->scale,
			map->player.pos.y * img->scale),
		new_ipoint2d((map->player.pos.x + map->player.dir.x) * img->scale,
			(map->player.pos.y + map->player.dir.y) * img->scale), 0x0000FF);
}
