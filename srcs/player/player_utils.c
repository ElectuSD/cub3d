/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 10:23:51 by fdeleard          #+#    #+#             */
/*   Updated: 2025/08/28 19:16:23 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_player.h"

bool	is_player(char c)
{
	return (c == 'N' || c == 'S' || c == 'W' || c == 'E');
}

t_dpoint2d		init_player_dir(t_directions dir)
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

t_directions	get_player_direction(char c)
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

char	*get_player_direction_str(t_directions dir)
{
	if (dir == NORTH)
		return ("NORTH");
	if (dir == SOUTH)
		return ("SOUTH");
	if (dir == WEST)
		return ("WEST");
	if (dir == EAST)
		return ("EAST");
	return ("UNKNOWN");
}
