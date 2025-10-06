/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <fdeleard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 03:31:30 by fdeleard          #+#    #+#             */
/*   Updated: 2025/10/06 10:48:06 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_str.h"

#include "cub3d_map.h"

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
