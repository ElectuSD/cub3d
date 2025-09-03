/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucnavar <lucnavar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 16:26:30 by lucnavar          #+#    #+#             */
/*   Updated: 2025/09/03 09:55:37 by lucnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft_mem.h"
#include "mlx.h"
#include <sys/time.h>

static void	clear_img(t_img *img, int color)
{
	ft_memset(img->addr, color, img->width * img->height * img->bytes_per_pixel);
}

static double	get_delta_time(t_cub3d *p)
{
	double			delta;
	struct timeval	cur_time;

	gettimeofday(&cur_time, NULL);
	delta = (cur_time.tv_sec - p->frametime.tv_sec) + (cur_time.tv_usec
			- p->frametime.tv_usec) / 1000000.0;
	p->frametime = cur_time;
	return (delta);
}

static bool	player_moved(t_cub3d *p)
{
	static t_dpoint2d	last_pos = {-1, -1};
	static t_dpoint2d	last_dir = {-1, -1};

	if (p->map.player.pos.x != last_pos.x || p->map.player.pos.y != last_pos.y
		|| p->map.player.dir.x != last_dir.x
		|| p->map.player.dir.y != last_dir.y)
	{
		last_pos = p->map.player.pos;
		last_dir = p->map.player.dir;
		return (true);
	}
	return (false);
}

void	render_scene(t_cub3d *p)
{
	draw_floor(&p->raycast, &p->map);
	draw_ceiling(&p->raycast, &p->map);
	draw_raycast(&p->raycast, &p->map);
	if (player_moved(p) || !p->is_updated)
	{
		clear_img(&p->minimap, 0x000000);
		draw_map(&p->minimap, &p->map);
		draw_player(&p->minimap, &p->map);
		p->is_updated = true;
	}
	draw_minimap_on_raycast(&p->raycast, &p->minimap);
}

int	render_main_loop(t_cub3d *p)
{
	double	dt;

	dt = get_delta_time(p);
	update_player(p, dt);
	render_scene(p);
	mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->raycast.img_ptr, 0, 0);
	if (is_key_pressed(ESC_KEY, p->map.player.keystate))
		free_cub3d_and_exit(p);
	return (0);
}
