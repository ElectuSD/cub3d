/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 11:05:06 by fdeleard          #+#    #+#             */
/*   Updated: 2025/09/11 10:57:18 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_map.h"
#include "cub3d_raycast.h"

static bool	is_wall(char c);

bool	is_in_map(t_map *map, t_dpoint2d v_ray_start)
{
	return (!(v_ray_start.x < map->cols && v_ray_start.x >= 0
			&& v_ray_start.y < map->rows && v_ray_start.y >= 0
			&& map->map[(int)v_ray_start.y][(int)v_ray_start.x] == '1'));
}

bool	has_hit_wall(char **map, t_ipoint2d v_map_check)
{
	return (is_wall(map[v_map_check.y][v_map_check.x]));
}

static bool	is_wall(char c)
{
	return (c == '1' || c == ' ');
}
