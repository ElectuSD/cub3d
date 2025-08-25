/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 10:29:19 by fdeleard          #+#    #+#             */
/*   Updated: 2025/08/25 14:46:58 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "mlx.h"
#include "libft_mem.h"
#include "libft_str.h"

#include "cub3d.h"
#include "cub3d_map.h"
#include "cub3d_utils.h"
#include "cub3d_render.h"
#include "cub3d_player.h"
#include "cub3d_parsing.h"

static bool	init_map(t_map *map, char *filename);
static void	get_map_infos(t_map *map);

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
	print_map_infos(&p.map);
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
		print_parser_error(error);
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
			{
				map->player.player_direction = get_player_direction(c);
				map->player.x = 22.3;//i + 0.5;
				map->player.y = 10.7;//map->rows + 0.5;
			}
			i++;
		}
		line_lenght = ft_strlen(map->map[map->rows]);
		if (line_lenght > map->cols)
			map->cols = line_lenght;
		map->rows++;
	}
}
