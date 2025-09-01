/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucnavar <lucnavar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 13:51:45 by fdeleard          #+#    #+#             */
/*   Updated: 2025/09/01 11:04:03 by lucnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cub3d.h"

static void	put_imgs_to_window(t_cub3d *p, t_img *raycast, t_img *minimap);
static void	clear_img(t_img *img, int color);

int	update_loop(void *params)
{
	t_cub3d				*p;

	p = params;
	if (!p->is_updated)
	{
		clear_img(&p->minimap, 0x000000);
		draw_map(&p->minimap, &p->map);
		draw_player(&p->minimap, &p->map);
		draw_floor(&p->raycast, &p->map);
		draw_ceiling(&p->raycast, &p->map);
		draw_raycast(&p->raycast, &p->map);
		put_imgs_to_window(p, &p->raycast, &p->minimap);
		p->is_updated = true;
	}
	return (0);
}

static void	put_imgs_to_window(t_cub3d *p, t_img *raycast, t_img *minimap)
{
	mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, raycast->img_ptr, 0, 0);
	mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, minimap->img_ptr, 0, 0);
}

static void	clear_img(t_img *img, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
		{
			draw_pixel(img, x, y, color);
			x++;
		}
		y++;
	}
}
