/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucnavar <lucnavar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 14:20:30 by lucnavar          #+#    #+#             */
/*   Updated: 2025/09/01 16:09:58 by lucnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_map.h"
#include "cub3d_minimap_utils.h"
#include <math.h>

bool	is_map_part(char c)
{
	return (is_player(c) || c == '1' || c == '0');
}

void	draw_grid_cell(t_img *img, int screen_x, int screen_y, int scale)
{
	t_ipoint2d	a;
	t_ipoint2d	b;

	a = new_ipoint2d(screen_x, screen_y);
	b = new_ipoint2d(screen_x + scale, screen_y + scale);
	if (a.x < 0)
		a.x = 0;
	if (a.y < 0)
		a.y = 0;
	if (b.x > img->width)
		b.x = img->width;
	if (b.y > img->height)
		b.y = img->height;
	draw_rectangle_fill(img, a, b, 0x696969);
}

void	draw_grid_row(t_img *img, t_map *map, size_t i, double *offsets)
{
	size_t	j;
	int		screen_x;
	int		screen_y;
	int		scale;

	j = 0;
	scale = img->scale;
	while (map->map[i][j])
	{
		if (is_map_part(map->map[i][j]))
		{
			screen_x = (j * scale) - offsets[0];
			screen_y = (i * scale) - offsets[1];
			if (screen_x >= -scale && screen_x < img->width
				&& screen_y >= -scale && screen_y < img->height)
				draw_grid_cell(img, screen_x, screen_y, scale);
		}
		j++;
	}
}

void	draw_wall(t_img *img, t_map *map, size_t i, size_t j)
{
	t_ipoint2d	a;
	t_ipoint2d	b;

	a = map_to_screen_coords(img, map, j, i);
	b = map_to_screen_coords(img, map, j + 1, i + 1);
	a.x += 1;
	a.y += 1;
	b.x -= 1;
	b.y -= 1;
	if (a.x < img->width && a.y < img->height && b.x > 0 && b.y > 0)
	{
		if (a.x < 0)
			a.x = 0;
		if (a.y < 0)
			a.y = 0;
		if (b.x > img->width)
			b.x = img->width;
		if (b.y > img->height)
			b.y = img->height;
		draw_rectangle_fill(img, a, b, 0xFFFFFF);
	}
}

void	draw_map_row(t_img *img, t_map *map, size_t i)
{
	size_t	j;

	j = 0;
	while (map->map[i][j])
	{
		if (map->map[i][j] == '1')
			draw_wall(img, map, i, j);
		j++;
	}
}
