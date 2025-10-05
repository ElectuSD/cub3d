/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <fdeleard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 03:09:31 by fdeleard          #+#    #+#             */
/*   Updated: 2025/10/05 04:06:20 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

#include "cub3d.h"
#include "cub3d_input.h"
#include "cub3d_render.h"

static int	key_press(int key, int *keystate);
static int	key_release(int key, int *keystate);

void	hook_events(t_cub3d *p)
{
	int	*keystate;

	keystate = p->map.player.keystate;
	mlx_hook(p->win_ptr, ON_DESTROY, 0L, free_cub3d_and_exit, p);
	mlx_hook(p->win_ptr, ON_KEYUP, 1L << 1, key_release, keystate);
	mlx_hook(p->win_ptr, ON_KEYDOWN, 1L << 0, key_press, keystate);
	mlx_loop_hook(p->mlx_ptr, render_loop, p);
}

static int	key_press(int key, int *keystate)
{
	if (key < MAX_KEYS)
		keystate[key] = 1;
	else if (key == ESC_KEY)
		keystate[0] = 1;
	else if (key == LEFT_ARROW)
		keystate[1] = 1;
	else if (key == RIGHT_ARROW)
		keystate[2] = 1;
	else if (key == LEFT_SHIFT)
		keystate[3] = 1;
	return (0);
}

static int	key_release(int key, int *keystate)
{
	if (key < MAX_KEYS)
		keystate[key] = 0;
	else if (key == ESC_KEY)
		keystate[0] = 0;
	else if (key == LEFT_ARROW)
		keystate[1] = 0;
	else if (key == RIGHT_ARROW)
		keystate[2] = 0;
	else if (key == LEFT_SHIFT)
		keystate[3] = 0;
	return (0);
}

bool	is_key_pressed(int key, int *keystate)
{
	if (key < MAX_KEYS)
		return (keystate[key]);
	else if (key == ESC_KEY)
		return (keystate[0]);
	else if (key == LEFT_ARROW)
		return (keystate[1]);
	else if (key == RIGHT_ARROW)
		return (keystate[2]);
	else if (key == LEFT_SHIFT)
		return (keystate[3]);
	return (0);
}
