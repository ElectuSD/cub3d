/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <fdeleard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 03:19:00 by fdeleard          #+#    #+#             */
/*   Updated: 2025/10/05 03:19:25 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "cub3d_map.h"
#include "cub3d_maths.h"

bool	is_in_map(t_map *map, t_dpoint2d v_ray_start)
{
	return (!(v_ray_start.x < map->cols && v_ray_start.x >= 0
			&& v_ray_start.y < map->rows && v_ray_start.y >= 0
			&& map->map[(int)v_ray_start.y][(int)v_ray_start.x] == '1'));
}
