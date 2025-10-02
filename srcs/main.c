/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 10:29:19 by fdeleard          #+#    #+#             */
/*   Updated: 2025/10/02 16:19:43 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/time.h>

#include "mlx.h"
#include "libft_mem.h"

#include "cub3d.h"
#include "cub3d_utils.h"
#include "cub3d_render.h"

int	main(int argc, char **argv)
{
	t_cub3d	p;

	ft_memset(&p, 0, sizeof(t_cub3d));
	if (argc != 2)
	{
		printf("Usage : ./cub3d <map_name>.cub\n");
		return (1);
	}
	if (!is_valid_filename(argv[1]))
	{
		printf("Wrong filename, need map with .cub\n");
		return (1);
	}
	if (!init_cub3d(&p, argv[1]))
	{
		free_cub3d(&p);
		return (1);
	}
	gettimeofday(&p.frametime, NULL);
	mlx_loop(p.mlx_ptr);
	return (0);
}
