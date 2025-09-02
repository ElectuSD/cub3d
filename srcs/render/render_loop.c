/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucnavar <lucnavar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 13:51:45 by fdeleard          #+#    #+#             */
/*   Updated: 2025/09/02 13:46:54 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>

#include "mlx.h"
#include "cub3d.h"

static void		clear_img(t_img *img, int color);
static int		update_player(t_cub3d *p, double dt);
static void		put_imgs_to_window(t_cub3d *p, t_img *raycast, t_img *minimap);
static double	get_delta_time(t_cub3d *p);

int	update_loop(void *params)
{
	double				dt;
	t_cub3d				*p;

	p = params;
	dt = get_delta_time(p);
	clear_img(&p->minimap, 0x696969);
	draw_map(&p->minimap, &p->map);
	draw_player(&p->minimap, &p->map);
	draw_floor(&p->raycast, &p->map);
	draw_ceiling(&p->raycast, &p->map);
	draw_raycast(&p->raycast, &p->map);
	update_player(p, dt);
	put_imgs_to_window(p, &p->raycast, &p->minimap);
	if (is_key_pressed(ESC_KEY, p->map.player.keystate))
		free_cub3d_and_exit(p);
	return (0);
}

static void	put_imgs_to_window(t_cub3d *p, t_img *raycast, t_img *minimap)
{
	mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, raycast->img_ptr, 0, 0);
	mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, minimap->img_ptr, 0, 0);
}

static void	clear_img(t_img *img, int color)
{
	draw_rectangle_fill(img,
		new_ipoint2d(0, 0),
		new_ipoint2d(MAP_WIDTH, MAP_HEIGHT), color);
}

static int	update_player(t_cub3d *p, double dt)
{
	t_player	*player;

	player = &p->map.player;
	player->move_speed = MOVE_SPEED * dt;
	player->rot_speed = ROT_SPEED * dt;
	if (is_key_pressed(W_KEY, p->map.player.keystate))
		move_up(player->move_speed, &p->map, &player->pos, &player->dir);
	if (is_key_pressed(S_KEY, p->map.player.keystate))
		move_down(player->move_speed, &p->map, &player->pos, &player->dir);
	if (is_key_pressed(D_KEY, p->map.player.keystate))
		rotate_right(player->rot_speed, &player->dir, &player->plane);
	if (is_key_pressed(A_KEY, p->map.player.keystate))
		rotate_left(player->rot_speed, &player->dir, &player->plane);
	return (0);
}

static double	get_delta_time(t_cub3d *p)
{
	double			delta;
	struct timeval	cur_time;

	gettimeofday(&cur_time, NULL);
	delta = (cur_time.tv_sec - p->frametime.tv_sec)
		+ (cur_time.tv_usec - p->frametime.tv_usec) / 1000000.0;
	p->frametime = cur_time;
	return (delta);
}
