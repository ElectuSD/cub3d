/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 11:00:51 by fdeleard          #+#    #+#             */
/*   Updated: 2025/08/21 11:08:38 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "mlx.h"
#include "cub3d.h"
#include "cub3d_render.h"

bool	init_mlx(t_cub3d *p)
{
	p->mlx_ptr = mlx_init();
	if (!p->mlx_ptr)
	{
		printf("Failed to init mlx\n");
		return (false);
	}
	p->win_ptr = mlx_new_window(p->mlx_ptr, 1920, 1080, "Cub3d");
	if (!p->win_ptr)
	{
		printf("Failed to create mlx window\n");
		return (false);
	}
	hook_events(p);
	return (true);
}
