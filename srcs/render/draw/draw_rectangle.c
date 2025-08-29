/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rectangle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 13:10:16 by fdeleard          #+#    #+#             */
/*   Updated: 2025/08/29 13:49:47 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_render.h"

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
