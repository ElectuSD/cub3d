/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 10:23:51 by fdeleard          #+#    #+#             */
/*   Updated: 2025/08/29 14:03:01 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_player.h"

void	set_player_infos(t_player *player, char c, int x, int y)
{
	player->player_direction = get_player_direction(c);
	player->dir = init_player_dir(player->player_direction);
	player->pos = new_dpoint2d(x + 0.5, y + 0.5);
	player->plane = init_player_plane(player->player_direction);
	player->rot_speed = ROT_SPEED;
	player->move_speed = MOVE_SPEED;
}

t_dpoint2d	init_player_plane(t_dirs dir)
{
	if (dir == NORTH)
		return (new_dpoint2d(PLANE_DEFAULT, 0));
	if (dir == SOUTH)
		return (new_dpoint2d(-PLANE_DEFAULT, 0));
	if (dir == WEST)
		return (new_dpoint2d(0, -PLANE_DEFAULT));
	if (dir == EAST)
		return (new_dpoint2d(0, PLANE_DEFAULT));
	return (new_dpoint2d(PLANE_DEFAULT, 0));
}

t_dpoint2d	init_player_dir(t_dirs dir)
{
	if (dir == NORTH)
		return (new_dpoint2d(0, -1));
	if (dir == SOUTH)
		return (new_dpoint2d(0, 1));
	if (dir == WEST)
		return (new_dpoint2d(-1, 0));
	if (dir == EAST)
		return (new_dpoint2d(1, 0));
	return (new_dpoint2d(0, -1));
}

t_dirs	get_player_direction(char c)
{
	if (c == 'N')
		return (NORTH);
	if (c == 'S')
		return (SOUTH);
	if (c == 'W')
		return (WEST);
	if (c == 'E')
		return (EAST);
	return (NORTH);
}

bool	is_player(char c)
{
	return (c == 'N' || c == 'S' || c == 'W' || c == 'E');
}
