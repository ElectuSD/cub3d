/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 10:56:45 by fdeleard          #+#    #+#             */
/*   Updated: 2025/08/22 14:11:32 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "cub3d_map.h"

void	print_map_infos(t_map *map)
{
	int	i;

	printf("Textures\n");
	printf("North Texture  : %s\n", map->textures.north);
	printf("South Texture  : %s\n", map->textures.south);
	printf("West Texture   : %s\n", map->textures.west);
	printf("East Texture   : %s\n", map->textures.east);
	printf("\nColors\n");
	printf("Ceiling Colors : R%d | G%d | B%d\n", map->ceiling.r, map->ceiling.g, map->ceiling.b);
	printf("Floor Colors   : R%d | G%d | B%d\n", map->floor.r, map->floor.g, map->floor.b);
	printf("\nMap\n");
	i = 0;
	while (map->map[i])
	{
		printf("%s\n", map->map[i]);
		i++;
	}
	printf("ROWS : %lu | COLS : %lu\n", map->rows, map->cols);
	printf("Player DIR : %s\n", get_player_direction_str(map->player.player_direction));
	printf("Player X,Y : %f | %f\n", map->player.x, map->player.y);
}
