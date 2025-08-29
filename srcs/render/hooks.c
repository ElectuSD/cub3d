/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 11:04:24 by fdeleard          #+#    #+#             */
/*   Updated: 2025/08/29 13:53:02 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cub3d.h"

static int	process_keys(int key, t_cub3d *p);
static int	process_player(int key, t_cub3d *p);

void	hook_events(t_cub3d *p)
{
	mlx_hook(p->win_ptr, ON_DESTROY, 0L, free_cub3d_and_exit, p);
	mlx_hook(p->win_ptr, ON_KEYDOWN, 1L << 0, process_player, p);
	mlx_key_hook(p->win_ptr, process_keys, p);
	mlx_loop_hook(p->mlx_ptr, update_loop, p);
}

static int	process_player(int key, t_cub3d *p)
{
	t_player	*player;

	player = &p->map.player;
	player->move_speed = MOVE_SPEED * 0.01;
	player->rot_speed = ROT_SPEED * 0.01;
	if (key == W_KEY)
		move_up(player->move_speed, &p->map, &player->pos, &player->dir);
	if (key == S_KEY)
		move_down(player->move_speed, &p->map, &player->pos, &player->dir);
	if (key == D_KEY)
		rotate_right(player->rot_speed, &player->dir, &player->plane);
	if (key == A_KEY)
		rotate_left(player->rot_speed, &player->dir, &player->plane);
	if (key == W_KEY || key == S_KEY || key == D_KEY || key == A_KEY)
		p->is_updated = false;
	return (0);
}

static int	process_keys(int key, t_cub3d *p)
{
	if (key == ESC_KEY)
	{
		free_cub3d(p);
		exit (0);
	}
	return (0);
}
