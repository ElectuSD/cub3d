/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_drawing_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 11:11:49 by fdeleard          #+#    #+#             */
/*   Updated: 2025/08/29 13:58:14 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_render.h"

int	get_color_on_img(t_img *img, int x, int y)
{
	int		color;
	char	*dst;

	dst = img->addr + (y * img->line_lenght + x * (img->bits_per_pixel / 8));
	color = *(unsigned int *)dst;
	return (color);
}

bool	is_east_or_north(int side, t_dpoint2d v_ray_dir)
{
	return ((side == 0 && v_ray_dir.x > 0) || (side == 1 && v_ray_dir.y < 0));
}
