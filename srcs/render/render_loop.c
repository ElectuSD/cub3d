/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 13:51:45 by fdeleard          #+#    #+#             */
/*   Updated: 2025/08/29 13:23:32 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cub3d.h"

static void	put_imgs_to_window(t_cub3d *p, t_img *raycast, t_img *minimap);

int	update_loop(void *params)
{
	t_cub3d				*p;

	p = params;
	if (!p->is_updated)
	{
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
