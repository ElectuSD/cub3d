/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 13:10:16 by fdeleard          #+#    #+#             */
/*   Updated: 2025/08/21 14:24:45 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_map.h"
#include "cub3d_render.h"

void	draw_map(t_img *img, t_map *map)
{
	char		c;
	size_t		i;
	size_t		j;
	t_point2d	a;
	t_point2d	b;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			c = map->map[i][j];
			if (c == '1')
			{
				a.x = j * 10;
				a.y = i * 10;
				b.x = (j + 1) * 10;
				b.y = (i + 1) * 10;
				draw_rectangle(img, a, b);
			}
			j++;
		}
		i++;
	}
}

void	draw_rectangle(t_img *img, t_point2d a, t_point2d b)
{
	t_point2d	buffer;

	buffer.x = a.x;
	buffer.y = b.y;
	draw_line(img, a, buffer);
	draw_line(img, b, buffer);
	buffer.x = b.x;
	buffer.y = a.y;
	draw_line(img, a, buffer);
	draw_line(img, b, buffer);
}

void	ft_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_lenght + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
