/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 11:04:24 by fdeleard          #+#    #+#             */
/*   Updated: 2025/08/27 12:31:04 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>

#include "mlx.h"
#include "cub3d.h"
#include "cub3d_render.h"

static bool	is_wall(char c);
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
	double	rot_speed;
	double	move_speed;

	rot_speed = 0.08;
	move_speed = 0.2;
	printf("KEYCODE : %d\n", key);
	if (key == UP || key == W_KEY)
	{
		if (is_wall(p->map.map[(int)p->map.player.pos.y][(int)(p->map.player.pos.x + p->map.player.dir.x * move_speed)]))
			p->map.player.pos.x += p->map.player.dir.x * move_speed;
		if (is_wall(p->map.map[(int)(p->map.player.pos.y + p->map.player.dir.y * move_speed)][(int)p->map.player.pos.x]))
			p->map.player.pos.y += p->map.player.dir.y * move_speed;
		p->is_updated = false;
	}
	if (key == DOWN || key == S_KEY)
	{
		if (is_wall(p->map.map[(int)p->map.player.pos.y][(int)(p->map.player.pos.x - p->map.player.dir.x * move_speed)]))
			p->map.player.pos.x -= p->map.player.dir.x * move_speed;
		if (is_wall(p->map.map[(int)(p->map.player.pos.y - p->map.player.dir.y * move_speed)][(int)p->map.player.pos.x]))
			p->map.player.pos.y -= p->map.player.dir.y * move_speed;
		p->is_updated = false;
	}
	if (key == RIGHT || key == D_KEY)
	{
		double	oldDirx = p->map.player.dir.x;
		p->map.player.dir.x = oldDirx * cos(rot_speed) - p->map.player.dir.y * sin(rot_speed);
		p->map.player.dir.y = oldDirx * sin(rot_speed) + p->map.player.dir.y * cos(rot_speed);

		double	oldPlanex = p->map.player.plane.x;
		p->map.player.plane.x = oldPlanex * cos(rot_speed) - p->map.player.plane.y * sin(rot_speed);
		p->map.player.plane.y = oldPlanex * sin(rot_speed) + p->map.player.plane.y * cos(rot_speed);

		p->is_updated = false;
	}
	if (key == LEFT || key == A_KEY)
	{
		double	oldDirx = p->map.player.dir.x;
		p->map.player.dir.x = oldDirx * cos(-rot_speed) - p->map.player.dir.y * sin(-rot_speed);
		p->map.player.dir.y = oldDirx * sin(-rot_speed) + p->map.player.dir.y * cos(-rot_speed);

		double	oldPlanex = p->map.player.plane.x;
		p->map.player.plane.x = oldPlanex * cos(-rot_speed) - p->map.player.plane.y * sin(-rot_speed);
		p->map.player.plane.y = oldPlanex * sin(-rot_speed) + p->map.player.plane.y * cos(-rot_speed);

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

static bool	is_wall(char c)
{
	return (c == '0' || c == 'N' || c == 'S' || c == 'W' || c == 'E');
}
