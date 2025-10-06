/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucnavar <lucnavar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 13:48:47 by fdeleard          #+#    #+#             */
/*   Updated: 2025/10/06 10:42:51 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_map.h"
#include "cub3d_draw.h"

static void			draw_map_row(t_img *img, t_map *map, size_t i);
static void			draw_wall(t_img *img, t_map *map, size_t i, size_t j);
static void			draw_minimap_on_raycast(t_img *raycast, t_img *minimap);
static t_ipoint2d	map_to_screen_coords(t_img *img, t_map *map, double map_x,
						double map_y);

void	draw_minimap(t_img *minimap, t_img *raycast, t_map *map)
{
	size_t	i;

	i = 0;
	draw_grid(minimap, map);
	while (map->map[i])
	{
		draw_map_row(minimap, map, i);
		i++;
	}
	draw_player(minimap, map);
	draw_minimap_on_raycast(raycast, minimap);
}

static void	draw_minimap_on_raycast(t_img *raycast, t_img *minimap)
{
	int				y;
	int				x;
	unsigned int	*raycast_pixel;
	unsigned int	*minimap_pixel;

	y = 0;
	while (y < minimap->height)
	{
		x = 0;
		while (x < minimap->width)
		{
			raycast_pixel = (unsigned int *)(raycast->addr
					+ ((y + 10) * raycast->line_lenght)
					+ ((x + 10) * raycast->bytes_per_pixel));
			minimap_pixel = (unsigned int *)(minimap->addr
					+ (y * minimap->line_lenght)
					+ (x * minimap->bytes_per_pixel));
			if (*minimap_pixel != 0x000000)
				*raycast_pixel = *minimap_pixel;
			else
				*raycast_pixel = 0x696969;
			x++;
		}
		y++;
	}
}

static void	draw_map_row(t_img *img, t_map *map, size_t i)
{
	size_t	j;

	j = 0;
	while (map->map[i][j])
	{
		if (map->map[i][j] == '1' || map->map[i][j] == ' ')
			draw_wall(img, map, i, j);
		j++;
	}
}

static void	draw_wall(t_img *img, t_map *map, size_t i, size_t j)
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

static t_ipoint2d	map_to_screen_coords(t_img *img, t_map *map, double map_x,
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
