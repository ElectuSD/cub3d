/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_floor_ceilling.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 18:52:38 by fdeleard          #+#    #+#             */
/*   Updated: 2025/08/28 20:03:41 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_map.h"

void	draw_floor(t_img *img, t_map *map)
{
	t_ipoint2d	mid_left;
	t_ipoint2d	bottom_right;

	mid_left = new_ipoint2d(0, img->height / 2.0);
	bottom_right = new_ipoint2d(img->width, img->height);
	draw_rectangle_fill(img, mid_left, bottom_right, color_to_int(map->floor));
}

void	draw_ceiling(t_img *img, t_map *map)
{
	t_ipoint2d	top_left;
	t_ipoint2d	mid_right;

	top_left = new_ipoint2d(0, 0);
	mid_right = new_ipoint2d(img->width, img->height / 2.0);
	draw_rectangle_fill(img, top_left, mid_right, color_to_int(map->ceiling));
}
