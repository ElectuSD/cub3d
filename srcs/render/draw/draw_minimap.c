/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucnavar <lucnavar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 13:48:47 by fdeleard          #+#    #+#             */
/*   Updated: 2025/09/01 11:11:16 by lucnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_map.h"

static bool			is_map_part(char c);
static t_ipoint2d	map_to_screen_coords(t_img *img, t_map *map, double map_x,
						double map_y);

void	draw_grid(t_img *img, t_map *map)
{
	int			scale;
	size_t		i;
	size_t		j;
	t_ipoint2d	a;
	t_ipoint2d	b;
	double		offset_x;
	double		offset_y;
	int			screen_x;
	int			screen_y;

	offset_x = (map->player.pos.x * img->scale) - (img->width / 2);
	offset_y = (map->player.pos.y * img->scale) - (img->height / 2);
	i = 0;
	scale = img->scale;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (is_map_part(map->map[i][j]))
			{
				screen_x = (j * scale) - offset_x;
				screen_y = (i * scale) - offset_y;
				if (screen_x >= -scale && screen_x < img->width
					&& screen_y >= -scale && screen_y < img->height)
				{
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
			}
			j++;
		}
		i++;
	}
}

void	draw_map(t_img *img, t_map *map)
{
	size_t		i;
	size_t		j;
	t_ipoint2d	a;
	t_ipoint2d	b;

	i = 0;
	draw_grid(img, map);
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == '1')
			{
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
			j++;
		}
		i++;
	}
}

static bool	is_map_part(char c)
{
	return (is_player(c) || c == '1' || c == '0');
}

static t_ipoint2d	map_to_screen_coords(t_img *img, t_map *map, double map_x,
		double map_y)
{
	double	offset_x;
	double	offset_y;
	int		screen_x;
	int		screen_y;

	offset_x = (map->player.pos.x * img->scale) - (img->width / 2);
	offset_y = (map->player.pos.y * img->scale) - (img->height / 2);
	screen_x = (map_x * img->scale) - offset_x;
	screen_y = (map_y * img->scale) - offset_y;
	return (new_ipoint2d(screen_x, screen_y));
}
