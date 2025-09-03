/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucnavar <lucnavar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 13:51:45 by fdeleard          #+#    #+#             */
/*   Updated: 2025/09/03 10:07:35 by lucnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx.h"


void	draw_minimap_on_raycast(t_img *raycast, t_img *minimap)
{
	int				y;
	char			*raycast_line;
	char			*minimap_line;
	unsigned int	*raycast_pixel;
	unsigned int	*minimap_pixel;
	int				x;

	y = 0;
	while (y < minimap->height)
	{
		raycast_line = raycast->addr + ((y + 10) * raycast->line_lenght);
		minimap_line = minimap->addr + (y * minimap->line_lenght);
		x = 0;
		while (x < minimap->width)
		{
			raycast_pixel = (unsigned int *)(raycast_line + ((x + 10) * raycast->bytes_per_pixel));
			minimap_pixel = (unsigned int *)(minimap_line + (x * minimap->bytes_per_pixel));
			if (*minimap_pixel != 0x000000)
				*raycast_pixel = *minimap_pixel;
			else
				*raycast_pixel = 0x696969;
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
