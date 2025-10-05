/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_wall.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <fdeleard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 03:16:23 by fdeleard          #+#    #+#             */
/*   Updated: 2025/10/05 03:17:45 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "cub3d_maths.h"

bool	is_wall(char c)
{
	return (c == '1' || c == ' ');
}

bool	has_hit_wall(char **map, t_ipoint2d v_map_check)
{
	return (is_wall(map[v_map_check.y][v_map_check.x]));
}
