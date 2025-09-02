/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 13:49:17 by fdeleard          #+#    #+#             */
/*   Updated: 2025/09/02 19:43:03 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_render.h"

void	draw_pixel(t_img *data, int x, int y, int color)
{
	unsigned int	*pixel;

	pixel = (unsigned int *)(data->addr
			+ (y * data->line_lenght + x * data->bytes_per_pixel));
	*pixel = color;
}
