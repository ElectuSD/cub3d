/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 13:28:05 by fdeleard          #+#    #+#             */
/*   Updated: 2025/08/29 13:44:21 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "cub3d_render.h"

static void	init_line(t_line *line, t_ipoint2d p1, t_ipoint2d p2, int color);

void	draw_line(t_img *img, t_ipoint2d p1, t_ipoint2d p2, int color)
{
	t_line	line;

	init_line(&line, p1, p2, color);
	while (42)
	{
		draw_pixel(img, p1.x, p1.y, color);
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
