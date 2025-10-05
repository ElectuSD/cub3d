/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_drawing_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 11:11:49 by fdeleard          #+#    #+#             */
/*   Updated: 2025/10/05 03:25:48 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "cub3d_draw.h"

int	get_color_on_img(t_img *img, int x, int y)
{
	unsigned int	*pixel;

	pixel = (unsigned int *)(img->addr
			+ (y * img->line_lenght + x * img->bytes_per_pixel));
	return (*pixel);
}

bool	is_east_or_north(int side, t_dpoint2d v_ray_dir)
{
	return ((side == 0 && v_ray_dir.x > 0) || (side == 1 && v_ray_dir.y < 0));
}
