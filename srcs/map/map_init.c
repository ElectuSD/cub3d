/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <fdeleard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 03:31:30 by fdeleard          #+#    #+#             */
/*   Updated: 2025/10/05 18:09:13 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <string.h>

#include "cub3d_map.h"
#include "libft_str.h"

void	get_map_infos(t_map *map)
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
