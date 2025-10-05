/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <fdeleard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 04:00:02 by fdeleard          #+#    #+#             */
/*   Updated: 2025/10/05 18:14:52 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

#include "cub3d.h"
#include "cub3d_draw.h"
#include "cub3d_player.h"
#include "cub3d_render.h"

int	render_loop(t_cub3d *p)
{
	double	dt;

	dt = get_delta_time(p);
	update_player(p, dt);
	clear_img(&p->minimap, 0x000000);
	draw_floor(&p->raycast, p->map.floor.color);
	draw_ceiling(&p->raycast, p->map.ceiling.color);
	draw_raycast(&p->raycast, &p->map);
	draw_crosshair(&p->raycast, CROSSHAIR_COLOR);
	draw_minimap(&p->minimap, &p->raycast, &p->map);
	mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->raycast.img_ptr, 0, 0);
	if (is_key_pressed(ESC_KEY, p->map.player.keystate))
		free_cub3d_and_exit(p);
	return (0);
}
