/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 11:04:24 by fdeleard          #+#    #+#             */
/*   Updated: 2025/08/25 10:42:19 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	if (key == UP)
	{
		p->map.player.y -= 0.2;
		p->is_updated = false;
	}
	if (key == DOWN)
	{
		p->map.player.y += 0.2;
		p->is_updated = false;
	}
	if (key == RIGHT)
	{
		p->map.player.x += 0.2;
		p->is_updated = false;
	}
	if (key == LEFT)
	{
		p->map.player.x -= 0.2;
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
