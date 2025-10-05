/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucnavar <lucnavar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 11:45:25 by fdeleard          #+#    #+#             */
/*   Updated: 2025/10/05 03:27:09 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "cub3d_map.h"

void	move_up(double ms, t_map *map, t_dpoint2d *pos, t_dpoint2d *dir)
{
	if (!is_wall(map->map[(int)pos->y][(int)(pos->x + dir->x * ms)]))
		pos->x += dir->x * ms;
	if (!is_wall(map->map[(int)(pos->y + dir->y * ms)][(int)pos->x]))
		pos->y += dir->y * ms;
}

void	move_down(double ms, t_map *map, t_dpoint2d *pos, t_dpoint2d *dir)
{
	if (!is_wall(map->map[(int)pos->y][(int)(pos->x - dir->x * ms)]))
		pos->x -= dir->x * ms;
	if (!is_wall(map->map[(int)(pos->y - dir->y * ms)][(int)pos->x]))
		pos->y -= dir->y * ms;
}

void	rotate_right(double rs, t_dpoint2d *dir, t_dpoint2d *plane)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = dir->x;
	old_plane_x = plane->x;
	dir->x = old_dir_x * cos(rs) - dir->y * sin(rs);
	dir->y = old_dir_x * sin(rs) + dir->y * cos(rs);
	plane->x = old_plane_x * cos(rs) - plane->y * sin(rs);
	plane->y = old_plane_x * sin(rs) + plane->y * cos(rs);
}

void	rotate_left(double rs, t_dpoint2d *dir, t_dpoint2d *plane)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = dir->x;
	old_plane_x = plane->x;
	dir->x = old_dir_x * cos(-rs) - dir->y * sin(-rs);
	dir->y = old_dir_x * sin(-rs) + dir->y * cos(-rs);
	plane->x = old_plane_x * cos(-rs) - plane->y * sin(-rs);
	plane->y = old_plane_x * sin(-rs) + plane->y * cos(-rs);
}
