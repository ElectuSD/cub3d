/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 13:28:05 by fdeleard          #+#    #+#             */
/*   Updated: 2025/08/28 20:25:50 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "cub3d_render.h"

void	draw_line(t_img *img, t_ipoint2d p1, t_ipoint2d p2, int color)
{
    int x0 = p1.x;
    int y0 = p1.y;
    int x1 = p2.x;
    int y1 = p2.y;

    t_line line;

    line.color = color;
    line.dx = abs(x1 - x0);
    line.dy = abs(y1 - y0);
    line.sx = (x0 < x1) ? 1 : -1;
    line.sy = (y0 < y1) ? 1 : -1;
    line.err = line.dx - line.dy;

    while (42)
    {
        draw_pixel(img, x0, y0, color);
        if (x0 == x1 && y0 == y1)
            break;

        int e2 = 2 * line.err;

        if (e2 > -line.dy)
        {
            line.err -= line.dy;
            x0 += line.sx;
        }
        if (e2 < line.dx)
        {
            line.err += line.dx;
            y0 += line.sy;
        }
    }
}
