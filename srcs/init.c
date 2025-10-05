/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <fdeleard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 03:52:32 by fdeleard          #+#    #+#             */
/*   Updated: 2025/10/05 17:31:09 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

#include "libft_mem.h"

#include "mlx.h"
#include "cub3d.h"
#include "cub3d_input.h"
#include "cub3d_draw.h"
#include "cub3d_parsing.h"

static int	open_file(char *filename);

bool	init_mlx(t_cub3d *p)
{
	p->mlx_ptr = mlx_init();
	if (!p->mlx_ptr)
	{
		printf("Failed to init mlx\n");
		return (false);
	}
	return (true);
}

bool	init_mlx_window(t_cub3d *p)
{
	p->win_ptr = mlx_new_window(p->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "Cub3d");
	if (!p->win_ptr)
	{
		printf("Failed to create mlx window\n");
		return (false);
	}
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
	if (!init_mlx(p) || !create_img(p) || !init_mlx_window(p))
		return (false);
	hook_events(p);
	return (error == NO_ERRORS);
}

static int	open_file(char *filename)
{
	int	fd;

	if (!filename)
		return (-1);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		printf("%s: %s\n", filename, strerror(errno));
		return (-1);
	}
	return (fd);
}
