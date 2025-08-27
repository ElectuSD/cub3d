/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 13:10:16 by fdeleard          #+#    #+#             */
/*   Updated: 2025/08/27 12:16:21 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "cub3d_map.h"
#include "cub3d_render.h"

void	draw_player(t_img *img, t_map *map)
{
	int	scale;

	scale = img->width / map->cols;
	printf("x : %f | y : %f\n", map->player.pos.x, map->player.pos.y);
	draw_rectangle_fill(img, new_point2d((map->player.pos.x - 0.25) * scale, (map->player.pos.y - 0.25) * scale),
		new_point2d((map->player.pos.x + 0.25) * scale, (map->player.pos.y + 0.25) * scale), 0xFFFF00);
	draw_line(img, new_point2d(map->player.pos.x * scale, map->player.pos.y * scale),
					new_point2d((map->player.pos.x + map->player.dir.x) * scale, (map->player.pos.y + map->player.dir.y) * scale), 0x0000FF);
}

void	draw_grid(t_img *img, t_map *map)
{
	int			scale;
	size_t		i;
	size_t		j;
	t_point2d	a;
	t_point2d	b;

	i = 0;
	scale = img->width / map->cols;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == '1' || map->map[i][j] == '0')
			{
				a = new_point2d(j * scale, (i * scale));
				b = new_point2d((j + 1) * scale, ((i + 1) * scale));
				draw_rectangle(img, a, b, 0x696969);
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
	t_point2d	a;
	t_point2d	b;

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
				a = new_point2d((j * scale) + 1, (i * scale) + 1);
				b = new_point2d(((j + 1) * scale) - 1, ((i + 1) * scale) - 1);
				draw_rectangle_fill(img, a, b, 0xFFFFFF);
			}
			j++;
		}
		i++;
	}
}

void	draw_rectangle_fill(t_img *img, t_point2d a, t_point2d b, int color)
{
	t_rec		rectangle;
	t_point2d	buffer;

	rectangle = new_rectangle(new_point2d(min(a.x, b.x), min(a.y, b.y)),
			new_point2d(max(a.x, b.x), max(a.y, b.y)));
	while (rectangle.tl.y <= rectangle.br.y)
	{
		buffer = new_point2d(rectangle.br.x, rectangle.tl.y);
		draw_line(img, rectangle.tl, buffer, color);
		rectangle.tl.y += 1;
	}
}

void	draw_rectangle(t_img *img, t_point2d a, t_point2d b, int color)
{
	t_point2d	buffer;
	t_rec		rectangle;

	rectangle = new_rectangle(new_point2d(min(a.x, b.x), min(a.y, b.y)),
			new_point2d(max(a.x, b.x), max(a.y, b.y)));
	buffer = new_point2d(rectangle.br.x, rectangle.tl.y);
	draw_line(img, rectangle.tl, buffer, color);
	draw_line(img, buffer, rectangle.br, color);
	buffer = new_point2d(rectangle.tl.x, rectangle.br.y);
	draw_line(img, rectangle.br, buffer, color);
	draw_line(img, buffer, rectangle.tl, color);
}

void	ft_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_lenght + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
