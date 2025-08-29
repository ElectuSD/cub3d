/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 13:10:16 by fdeleard          #+#    #+#             */
/*   Updated: 2025/08/28 20:02:32 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "cub3d_map.h"
#include "cub3d_render.h"

void	draw_player(t_img *img, t_map *map)
{
	draw_rectangle_fill(img, new_ipoint2d((map->player.pos.x - 0.25) * img->scale, (map->player.pos.y - 0.25) * img->scale),
		new_ipoint2d((map->player.pos.x + 0.25) * img->scale, (map->player.pos.y + 0.25) * img->scale), 0xFF0000);
	draw_line(img, new_ipoint2d(map->player.pos.x * img->scale, map->player.pos.y * img->scale),
					new_ipoint2d((map->player.pos.x + map->player.dir.x) * img->scale, (map->player.pos.y + map->player.dir.y) * img->scale), 0x0000FF);
}

void	draw_grid(t_img *img, t_map *map)
{
	int			scale;
	size_t		i;
	size_t		j;
	t_ipoint2d	a;
	t_ipoint2d	b;

	i = 0;
	scale = img->width / map->cols;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (is_player(map->map[i][j]) || map->map[i][j] == '1' || map->map[i][j] == '0')
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
	scale = img->width / map->cols;
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

void	draw_rectangle_fill(t_img *img, t_ipoint2d a, t_ipoint2d b, int color)
{
	t_rec		rectangle;
	t_ipoint2d	buffer;

	rectangle = new_rectangle(new_ipoint2d(min(a.x, b.x), min(a.y, b.y)),
			new_ipoint2d(max(a.x, b.x), max(a.y, b.y)));
	while (rectangle.tl.y <= rectangle.br.y)
	{
		buffer = new_ipoint2d(rectangle.br.x, rectangle.tl.y);
		draw_line(img, rectangle.tl, buffer, color);
		rectangle.tl.y += 1;
	}
}

void	draw_rectangle(t_img *img, t_ipoint2d a, t_ipoint2d b, int color)
{
	t_ipoint2d	buffer;
	t_rec		rectangle;

	rectangle = new_rectangle(new_ipoint2d(min(a.x, b.x), min(a.y, b.y)),
			new_ipoint2d(max(a.x, b.x), max(a.y, b.y)));
	buffer = new_ipoint2d(rectangle.br.x, rectangle.tl.y);
	draw_line(img, rectangle.tl, buffer, color);
	draw_line(img, buffer, rectangle.br, color);
	buffer = new_ipoint2d(rectangle.tl.x, rectangle.br.y);
	draw_line(img, rectangle.br, buffer, color);
	draw_line(img, buffer, rectangle.tl, color);
}

void	draw_pixel(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_lenght + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
