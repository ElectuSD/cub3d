/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 13:28:05 by fdeleard          #+#    #+#             */
/*   Updated: 2025/09/02 20:26:02 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft_mem.h"
#include "libft_utils.h"

#include "cub3d_render.h"

static void	init_line(t_line *line, t_ipoint2d p1, t_ipoint2d p2, int c);
static void	draw_vertical_line(t_img *img, t_ipoint2d a, int y2, int color);
static void	draw_horizontal_line(t_img *img, t_ipoint2d a, int x, int color);
static void	bressenham_line(t_img *img, t_ipoint2d p1, t_ipoint2d p2, int c);

void	draw_line(t_img *img, t_ipoint2d p1, t_ipoint2d p2, int color)
{
	if (p1.x == p2.x)
		draw_vertical_line(img, p1, p2.y, color);
	else if (p1.y == p2.y)
		draw_horizontal_line(img, p1, p2.x, color);
	else
		bressenham_line(img, p1, p2, color);
}

static void	draw_horizontal_line(t_img *img, t_ipoint2d a, int x, int color)
{
	unsigned int	*start;
	int				width;
	int				i;

	if (a.y < 0 || a.y >= img->height)
		return ;
	if (a.x > x)
		ft_swap_int(&a.x, &x);
	if (a.x < 0)
		a.x = 0;
	if (x >= img->width)
		x = img->width - 1;
	i = 0;
	width = x - a.x + 1;
	if (width <= 0)
		return ;
	start = (unsigned int *)(img->addr
			+ (a.y * img->line_lenght + a.x * img->bytes_per_pixel));
	if (width > 8 && (color & 0xFF) == ((color >> 8) & 0xFF)
		&& ((color >> 8) & 0xFF) == ((color >> 16) & 0xFF))
		ft_memset(start, color & 0xFF, width * 4);
	else
		while (i < width)
			start[i++] = color;
}

static void	draw_vertical_line(t_img *img, t_ipoint2d a, int y2, int color)
{
	unsigned int	*pixel;
	int				line_step;
	int				height;
	int				i;

	if (a.x < 0 || a.x >= img->width)
		return ;
	if (a.y > y2)
		ft_swap_int(&a.y, &y2);
	if (a.y < 0)
		a.y = 0;
	if (y2 >= img->height)
		y2 = img->height - 1;
	i = 0;
	height = y2 - a.y + 1;
	if (height <= 0)
		return ;
	pixel = (unsigned int *)(img->addr
			+ (a.y * img->line_lenght + a.x * img->bytes_per_pixel));
	line_step = img->line_lenght / img->bytes_per_pixel;
	while (i++ < height)
	{
		*pixel = color;
		pixel += line_step;
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
