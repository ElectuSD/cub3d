/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucnavar <lucnavar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 13:49:17 by fdeleard          #+#    #+#             */
/*   Updated: 2025/10/05 02:52:33 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_draw.h"

void	draw_pixel(t_img *data, int x, int y, int color)
{
	unsigned int	*pixel;

	pixel = (unsigned int *)(data->addr
			+ (y * data->line_lenght + x * data->bytes_per_pixel));
	*pixel = color;
}
