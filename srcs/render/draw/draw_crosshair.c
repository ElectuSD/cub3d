/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_crosshair.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 13:53:32 by fdeleard          #+#    #+#             */
/*   Updated: 2025/09/03 13:57:40 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_render.h"

void	draw_crosshair(t_img *img, int color)
{
	t_ipoint2d	middle_screen;

	middle_screen = new_ipoint2d(img->width / 2, img->height / 2);
	draw_rectangle_fill(img,
		new_ipoint2d(middle_screen.x - 3, middle_screen.y - 20),
		new_ipoint2d(middle_screen.x + 3, middle_screen.y - 5), color);
	draw_rectangle_fill(img,
		new_ipoint2d(middle_screen.x - 3, middle_screen.y + 20),
		new_ipoint2d(middle_screen.x + 3, middle_screen.y + 5), color);
	draw_rectangle_fill(img,
		new_ipoint2d(middle_screen.x - 20, middle_screen.y - 3),
		new_ipoint2d(middle_screen.x - 5, middle_screen.y + 3), color);
	draw_rectangle_fill(img,
		new_ipoint2d(middle_screen.x + 20, middle_screen.y - 3),
		new_ipoint2d(middle_screen.x + 5, middle_screen.y + 3), color);
}
