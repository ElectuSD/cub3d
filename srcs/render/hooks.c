/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 11:04:24 by fdeleard          #+#    #+#             */
/*   Updated: 2025/09/01 11:06:00 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "mlx.h"
#include "cub3d.h"

int			key_press(int key, int *keystate);
int			key_release(int key, int *keystate);

void	hook_events(t_cub3d *p)
{
	int	*keystate;

	keystate = p->map.player.keystate;
	mlx_hook(p->win_ptr, ON_DESTROY, 0L, free_cub3d_and_exit, p);
	mlx_hook(p->win_ptr, ON_KEYUP, 1L << 1, key_release, keystate);
	mlx_hook(p->win_ptr, ON_KEYDOWN, 1L << 0, key_press, keystate);
	mlx_loop_hook(p->mlx_ptr, update_loop, p);
}

int	key_press(int key, int *keystate)
{
	if (key < MAX_KEYS)
		keystate[key] = 1;
	else if (key == ESC_KEY)
		keystate[0] = 1;
	return (0);
}

int	key_release(int key, int *keystate)
{
	if (key < MAX_KEYS)
		keystate[key] = 0;
	else if (key == ESC_KEY)
		keystate[0] = 0;
	return (0);
}

bool	is_key_pressed(int key, int *keystate)
{
	if (key < MAX_KEYS)
		return (keystate[key]);
	else if (key == ESC_KEY)
		return (keystate[0]);
	return (0);
}
