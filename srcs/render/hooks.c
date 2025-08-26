/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 11:04:24 by fdeleard          #+#    #+#             */
/*   Updated: 2025/08/25 21:37:55 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>

#include "mlx.h"
#include "cub3d.h"
#include "cub3d_render.h"

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
	printf("KEYCODE : %d\n", key);
	if (key == Q_KEY)
	{
		if (p->map.player.angle < 0)
			p->map.player.angle = 2 * M_PI;
		if (p->map.player.angle > 2 * M_PI)
			p->map.player.angle = 0;
		p->map.player.angle -= 0.05;
		p->is_updated = false;
	}
	if (key == E_KEY)
	{
		if (p->map.player.angle < 0)
			p->map.player.angle = 2 * M_PI;
		if (p->map.player.angle > 2 * M_PI)
			p->map.player.angle = 0;
		p->map.player.angle += 0.05;
		p->is_updated = false;
	}
	if (key == UP || key == W_KEY)
	{
		p->map.player.pos.y -= 0.2;
		p->is_updated = false;
	}
	if (key == DOWN || key == S_KEY)
	{
		p->map.player.pos.y += 0.2;
		p->is_updated = false;
	}
	if (key == RIGHT || key == D_KEY)
	{
		p->map.player.pos.x += 0.2;
		p->is_updated = false;
	}
	if (key == LEFT || key == A_KEY)
	{
		p->map.player.pos.x -= 0.2;
		p->is_updated = false;
	}
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
