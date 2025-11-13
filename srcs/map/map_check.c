/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <fdeleard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 03:19:00 by fdeleard          #+#    #+#             */
/*   Updated: 2025/11/12 12:51:34 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_map.h"

bool	is_in_map(t_map *map, t_dpoint2d v_ray_start)
{
	return (!(v_ray_start.x < map->cols && v_ray_start.x >= 0
			&& v_ray_start.y < map->rows && v_ray_start.y >= 0
			&& map->map[(int)v_ray_start.y][(int)v_ray_start.x] == '1'));
}

bool	is_map_part(char c)
{
	return (is_player(c) || c == '1' || c == '0');
}
