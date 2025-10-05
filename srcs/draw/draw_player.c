/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucnavar <lucnavar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 13:48:17 by fdeleard          #+#    #+#             */
/*   Updated: 2025/10/05 02:46:23 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_map.h"
#include "cub3d_draw.h"
#include "cub3d_maths.h"

void	draw_player(t_img *img, t_map *map)
{
	int		center_x;
	int		center_y;
	int		player_size;
	double	dir_x;
	double	dir_y;

	center_x = img->width / 2;
	center_y = img->height / 2;
	player_size = img->scale / 4;
	if (player_size < 2)
		player_size = 2;
	draw_rectangle_fill(img, new_ipoint2d(center_x - player_size, center_y
			- player_size), new_ipoint2d(center_x + player_size, center_y
			+ player_size), 0xFF0000);
	dir_x = center_x + (map->player.dir.x * img->scale);
	dir_y = center_y + (map->player.dir.y * img->scale);
	draw_line(img, new_ipoint2d(center_x, center_y), new_ipoint2d(dir_x, dir_y),
		0x0000FF);
}
