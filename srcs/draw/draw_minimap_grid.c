/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap_grid.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <fdeleard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 02:16:30 by fdeleard          #+#    #+#             */
/*   Updated: 2025/11/12 12:52:10 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_map.h"
#include "cub3d_draw.h"

static void	draw_grid_row(t_img *img, t_map *map, size_t i, double *offsets);
static void	draw_grid_cell(t_img *img, int screen_x, int screen_y, int scale);

void	draw_grid(t_img *img, t_map *map)
{
	size_t	i;
	double	offsets[2];

	i = 0;
	offsets[0] = (map->player.pos.x * img->scale) - (img->width / 2.0);
	offsets[1] = (map->player.pos.y * img->scale) - (img->height / 2.0);
	while (map->map[i])
	{
		draw_grid_row(img, map, i, offsets);
		i++;
	}
}

static void	draw_grid_row(t_img *img, t_map *map, size_t i, double *offsets)
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

static void	draw_grid_cell(t_img *img, int screen_x, int screen_y, int scale)
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
	draw_rectangle_fill(img, a, b, MINIMAP_GRID_COLOR);
}
