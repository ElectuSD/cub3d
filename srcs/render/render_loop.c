/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucnavar <lucnavar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 13:51:45 by fdeleard          #+#    #+#             */
/*   Updated: 2025/09/01 16:24:11 by lucnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx.h"

void	draw_minimap_on_raycast(t_img *raycast, t_img *minimap)
{
	int		x;
	int		y;
	int		color;
	char	*pixel;

	y = 0;
	while (y < minimap->height)
	{
		x = 0;
		while (x < minimap->width)
		{
			draw_pixel(raycast, x + 10, y + 10, 0x000000);
			x++;
		}
		y++;
	}
	y = 0;
	while (y < minimap->height)
	{
		x = 0;
		while (x < minimap->width)
		{
			pixel = minimap->addr + (y * minimap->line_lenght + x
					* minimap->bytes_per_pixel);
			color = *(int *)pixel;
			if (color != 0x000000)
				draw_pixel(raycast, x + 10, y + 10, color);
			x++;
		}
		y++;
	}
}

int	update_loop(void *params)
{
	t_cub3d	*p;

	p = (t_cub3d *)params;
	return (render_main_loop(p));
}
