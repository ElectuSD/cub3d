/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 13:28:05 by fdeleard          #+#    #+#             */
/*   Updated: 2025/08/22 13:44:21 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "cub3d_render.h"

static void	get_next_pixel(t_line *line, t_point2d *p1);
static void	bresenham_line(t_img *img, t_point2d p1, t_point2d p2, t_line line);

void	draw_line(t_img *img, t_point2d p1, t_point2d p2, int color)
{
	t_line	line;

	line.color = color;
	line.dx = fabs(p2.x - p1.x);
	line.dy = fabs(p2.y - p1.y);
	if (p1.x < p2.x)
		line.sx = 1;
	else
		line.sx = -1;
	if (p1.y < p2.y)
		line.sy = 1;
	else
		line.sy = -1;
	line.err = line.dx - line.dy;
	bresenham_line(img, p1, p2, line);
}

static void	bresenham_line(t_img *img, t_point2d p1, t_point2d p2, t_line line)
{
	double	distance;
	double	progress;

	distance = sqrt(line.dx * line.dx + line.dy * line.dy);
	progress = 0.0;
	while (1)
	{
		if (p1.x >= 0 && p1.x < img->width && p1.y >= 0 && p1.y <= img->height)
			ft_mlx_pixel_put(img, p1.x, p1.y, line.color);
		if ((int)p1.x == (int)p2.x && (int)p1.y == (int)p2.y)
			break ;
		get_next_pixel(&line, &p1);
		progress += 1.0 / distance;
		if (progress > 1.0)
			progress = 1.0;
	}
}

static void	get_next_pixel(t_line *line, t_point2d *p1)
{
	line->e2 = line->err * 2;
	if (line->e2 > -line->dy)
	{
		line->err -= line->dy;
		p1->x += line->sx;
	}
	if (line->e2 < line->dx)
	{
		line->err += line->dx;
		p1->y += line->sy;
	}
}
