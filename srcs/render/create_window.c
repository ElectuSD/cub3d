/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 11:00:51 by fdeleard          #+#    #+#             */
/*   Updated: 2025/10/02 16:19:44 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "libft_mem.h"

#include "mlx.h"
#include "cub3d.h"
#include "cub3d_utils.h"
#include "cub3d_render.h"
#include "cub3d_parsing.h"

bool	init_mlx(t_cub3d *p)
{
	p->mlx_ptr = mlx_init();
	if (!p->mlx_ptr)
	{
		printf("Failed to init mlx\n");
		return (false);
	}
	p->win_ptr = mlx_new_window(p->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "Cub3d");
	if (!p->win_ptr)
	{
		printf("Failed to create mlx window\n");
		return (false);
	}
	hook_events(p);
	return (true);
}

bool	init_cub3d(t_cub3d *p, char *filename)
{
	t_error	error;

	ft_memset(&p->map, 0, sizeof(t_map));
	p->map.fd = open_file(filename);
	if (p->map.fd == -1)
		return (false);
	error = parse(&p->map);
	if (error)
	{
		print_error_helper(error);
		return (false);
	}
	get_map_infos(&p->map);
	if (!init_mlx(p))
		return (false);
	if (!create_img(p))
		return (false);
	return (error == NO_ERRORS);
}
