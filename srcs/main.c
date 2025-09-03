/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 10:29:19 by fdeleard          #+#    #+#             */
/*   Updated: 2025/09/03 10:49:54 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/time.h>

#include "mlx.h"
#include "libft_mem.h"
#include "libft_str.h"

#include "cub3d.h"
#include "cub3d_map.h"
#include "cub3d_utils.h"
#include "cub3d_render.h"
#include "cub3d_player.h"
#include "cub3d_parsing.h"

static bool	create_img(t_cub3d *p);
static void	get_map_infos(t_map *map);
static bool	init_map(t_map *map, char *filename);

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
	if (!init_map(&p.map, argv[1]))
		return (1);
	if (!init_mlx(&p))
		return (1);
	if (!create_img(&p))
		return (1);
	gettimeofday(&p.frametime, NULL);
	mlx_loop(p.mlx_ptr);
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
	{
		print_parser_error(error);
		return (false);
	}
	get_map_infos(map);
	return (error == NO_ERRORS);
}

static void	get_map_infos(t_map *map)
{
	char	c;
	size_t	i;
	size_t	line_lenght;

	map->rows = 0;
	map->cols = 0;
	while (map->map[map->rows])
	{
		i = 0;
		while (map->map[map->rows][i])
		{
			c = map->map[map->rows][i];
			if (is_player(c))
				set_player_infos(&map->player, c, i, map->rows);
			i++;
		}
		line_lenght = ft_strlen(map->map[map->rows]);
		if (line_lenght > map->cols)
			map->cols = line_lenght;
		map->rows++;
	}
}

static bool	create_img(t_cub3d *p)
{
	if (load_textures(p, &p->map))
	{
		printf("Error\nFailed to load textures\n");
		return (false);
	}
	create_minimap_img(p);
	create_raycast_img(p);
	return (true);
}
