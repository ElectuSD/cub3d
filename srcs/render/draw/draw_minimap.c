/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 13:48:47 by fdeleard          #+#    #+#             */
/*   Updated: 2025/09/01 10:23:46 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_map.h"

static bool	is_map_part(char c);

void	draw_grid(t_img *img, t_map *map)
{
	int			scale;
	size_t		i;
	size_t		j;
	t_ipoint2d	a;
	t_ipoint2d	b;

	i = 0;
	scale = img->width / map->rows;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (is_map_part(map->map[i][j]))
			{
				a = new_ipoint2d(j * scale, (i * scale));
				b = new_ipoint2d((j + 1) * scale, ((i + 1) * scale));
				draw_rectangle_fill(img, a, b, 0x696969);
			}
			j++;
		}
		i++;
	}
}

void	draw_map(t_img *img, t_map *map)
{
	int			scale;
	size_t		i;
	size_t		j;
	t_ipoint2d	a;
	t_ipoint2d	b;

	i = 0;
	scale = img->width / map->rows;
	draw_grid(img, map);
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == '1')
			{
				a = new_ipoint2d((j * scale) + 1, (i * scale) + 1);
				b = new_ipoint2d(((j + 1) * scale) - 1, ((i + 1) * scale) - 1);
				draw_rectangle_fill(img, a, b, 0xFFFFFF);
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
