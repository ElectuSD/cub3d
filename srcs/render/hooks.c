/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 11:04:24 by fdeleard          #+#    #+#             */
/*   Updated: 2025/08/21 11:21:43 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cub3d.h"
#include "cub3d_render.h"

static int	process_keys(int key, t_cub3d *p);

void	hook_events(t_cub3d *p)
{
	mlx_key_hook(p->win_ptr, process_keys, p);
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
