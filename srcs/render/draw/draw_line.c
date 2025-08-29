/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 13:28:05 by fdeleard          #+#    #+#             */
/*   Updated: 2025/08/29 14:28:38 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>

#include "cub3d_render.h"

static void	init_line(t_line *line, t_ipoint2d p1, t_ipoint2d p2, int c);
static void	bressenham_line(t_img *img, t_ipoint2d p1, t_ipoint2d p2, int c);
static void	draw_simple_line(t_img *img, t_ipoint2d p1, t_ipoint2d p2, int c);

void	draw_line(t_img *img, t_ipoint2d p1, t_ipoint2d p2, int color)
{
	if (p1.x == p2.x || p1.y == p2.y)
		draw_simple_line(img, p1, p2, color);
	else
		bressenham_line(img, p1, p2, color);
}

static void	draw_simple_line(t_img *img, t_ipoint2d p1, t_ipoint2d p2, int c)
{
	t_ipoint2d	buffer;

	if (p1.x == p2.x)
	{
		buffer = new_ipoint2d(p1.x, fmin(p1.y, p2.y));
		while (buffer.y != fmax(p1.y, p2.y))
		{
			buffer.y += 1;
			draw_pixel(img, buffer.x, buffer.y, c);
		}
	}
	else
	{
		buffer = new_ipoint2d(fmin(p1.x, p2.x), p1.y);
		while (buffer.x != fmax(p1.x, p2.x))
		{
			buffer.x += 1;
			draw_pixel(img, buffer.x, buffer.y, c);
		}
	}
}

static void	bressenham_line(t_img *img, t_ipoint2d p1, t_ipoint2d p2, int c)
{
	t_line	line;

	init_line(&line, p1, p2, c);
	while (42)
	{
		draw_pixel(img, p1.x, p1.y, c);
		if (p1.x == p2.x && p1.y == p2.y)
			break ;
		line.e2 = 2 * line.err;
		if (line.e2 > -line.dy)
		{
			line.err -= line.dy;
			p1.x += line.sx;
		}
		if (line.e2 < line.dx)
		{
			line.err += line.dx;
			p1.y += line.sy;
		}
	}
}

static void	init_line(t_line *line, t_ipoint2d p1, t_ipoint2d p2, int color)
{
	line->color = color;
	line->dx = abs(p2.x - p1.x);
	line->dy = abs(p2.y - p1.y);
	if (p1.x < p2.x)
		line->sx = 1;
	else
		line->sx = -1;
	if (p1.y < p2.y)
		line->sy = 1;
	else
		line->sy = -1;
	line->err = line->dx - line->dy;
}
