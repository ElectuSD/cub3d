/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_strafe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucnavar <lucnavar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 16:26:30 by lucnavar          #+#    #+#             */
/*   Updated: 2025/09/03 10:39:55 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_player.h"
#include "cub3d_map.h"

static bool	is_wall(char c)
{
	return (c == '1' || c == ' ');
}

void	move_left(double ms, t_map *map, t_dpoint2d *pos, t_dpoint2d *plane)
{
	t_dpoint2d	strafe_dir;
	double		new_x;
	double		new_y;

	strafe_dir.x = -plane->x;
	strafe_dir.y = -plane->y;
	new_x = pos->x + strafe_dir.x * ms;
	new_y = pos->y + strafe_dir.y * ms;
	if (!is_wall(map->map[(int)pos->y][(int)new_x]))
		pos->x = new_x;
	if (!is_wall(map->map[(int)new_y][(int)pos->x]))
		pos->y = new_y;
}

void	move_right(double ms, t_map *map, t_dpoint2d *pos, t_dpoint2d *plane)
{
	t_dpoint2d	strafe_dir;
	double		new_x;
	double		new_y;

	strafe_dir.x = plane->x;
	strafe_dir.y = plane->y;
	new_x = pos->x + strafe_dir.x * ms;
	new_y = pos->y + strafe_dir.y * ms;
	if (!is_wall(map->map[(int)pos->y][(int)new_x]))
		pos->x = new_x;
	if (!is_wall(map->map[(int)new_y][(int)pos->x]))
		pos->y = new_y;
}
