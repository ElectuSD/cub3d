/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucnavar <lucnavar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 13:48:47 by fdeleard          #+#    #+#             */
/*   Updated: 2025/09/03 09:43:59 by lucnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_map.h"
#include "cub3d_minimap_utils.h"
#include <math.h>

t_ipoint2d	map_to_screen_coords(t_img *img, t_map *map, double map_x,
		double map_y)
{
	double	offset_x;
	double	offset_y;
	int		screen_x;
	int		screen_y;

	offset_x = (map->player.pos.x * img->scale) - (img->width / 2.0);
	offset_y = (map->player.pos.y * img->scale) - (img->height / 2.0);
	screen_x = (map_x * img->scale) - offset_x;
	screen_y = (map_y * img->scale) - offset_y;
	return (new_ipoint2d(screen_x, screen_y));
}

void	draw_grid(t_img *img, t_map *map)
{
	size_t	i;
	double	offsets[2];

	offsets[0] = (map->player.pos.x * img->scale) - (img->width / 2);
	offsets[1] = (map->player.pos.y * img->scale) - (img->height / 2);
	i = 0;
	while (map->map[i])
	{
		draw_grid_row(img, map, i, offsets);
		i++;
	}
}

void	draw_map(t_img *img, t_map *map)
{
	size_t	i;

	i = 0;
	draw_grid(img, map);
	while (map->map[i])
	{
		draw_map_row(img, map, i);
		i++;
	}
}
