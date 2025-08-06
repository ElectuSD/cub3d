/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 10:29:19 by fdeleard          #+#    #+#             */
/*   Updated: 2025/08/06 14:08:47 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "cub3d_map.h"
#include "cub3d_utils.h"
#include "cub3d_parsing.h"

void	print_map_infos(t_map *map);
void	print_parser_error(t_error error);

int	main(int argc, char **argv)
{
	int		error;
	t_map	map;

	if (argc != 2)
	{
		printf("Usage : ./cub3d <map_name>.cub\n");
		return (1);
	}
	map.fd = open_file(argv[1]);
	if (map.fd == -1)
		return (1);
	error = parse(&map);
	if (error)
		print_parser_error(error);
	else
		print_map_infos(&map);
	return (0);
}

void	print_parser_error(t_error error)
{
	if (error == NORTH_DUPPLICATE)
		printf("Error\nNorth texture dupplicate in map\n");
	if (error == SOUTH_DUPPLICATE)
		printf("Error\nSouth texture dupplicate in map\n");
	if (error == WEST_DUPPLICATE)
		printf("Error\nWest texture dupplicate in map\n");
	if (error == EAST_DUPPLICATE)
		printf("Error\nEast texture dupplicate in map\n");
	if (error == CEILING_DUPPLICATE)
		printf("Error\nCeiling colors dupplicate in map\n");
	if (error == FLOOR_DUPPLICATE)
		printf("Error\nFloor colors dupplicate in map\n");
}

void	print_map_infos(t_map *map)
{
	printf("Textures\n");
	printf("North Texture : %s\n", map->textures.north);
	printf("South Texture : %s\n", map->textures.south);
	printf("West Texture : %s\n", map->textures.west);
	printf("East Texture : %s\n", map->textures.east);
	printf("\nColors\n");
	printf("Ceiling Colors : R%d | G%d | B%d\n", map->ceiling.r, map->ceiling.g, map->ceiling.b);
	printf("Floor Colors : R%d | G%d | B%d\n", map->floor.r, map->floor.g, map->floor.b);
}
