/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 10:29:19 by fdeleard          #+#    #+#             */
/*   Updated: 2025/08/21 11:26:28 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "mlx.h"
#include "libft_mem.h"

#include "cub3d.h"
#include "cub3d_map.h"
#include "cub3d_utils.h"
#include "cub3d_render.h"
#include "cub3d_parsing.h"

static bool	init_map(t_map *map, char *filename);

int	main(int argc, char **argv)
{
	t_cub3d	p;

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
	if (!init_map(&p.map, argv[1]))
	{
		return (1);
	}
	if (!init_mlx(&p))
	{
		return (1);
	}
	mlx_loop(p.mlx_ptr);
	//print_map_infos(&p.map);
	return (0);
}

static bool	init_map(t_map *map, char *filename)
{
	t_error	error;

	ft_memset(map, 0, sizeof(t_map));
	map->fd = open_file(filename);
	if (map->fd == -1)
		return (false);
	error = parse(map);
	if (error)
		print_parser_error(error);
	return (error == NO_ERRORS);
}
