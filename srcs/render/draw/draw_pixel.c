/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucnavar <lucnavar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 13:49:17 by fdeleard          #+#    #+#             */
/*   Updated: 2025/09/01 16:14:49 by lucnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_render.h>

void	draw_pixel(t_img *data, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < data->width && y >= 0 && y < data->height)
	{
		dst = data->addr + (y * data->line_lenght + x * data->bytes_per_pixel);
		*(unsigned int *)dst = color;
	}
}
