/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 10:23:51 by fdeleard          #+#    #+#             */
/*   Updated: 2025/08/25 21:16:04 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "cub3d_player.h"

bool	is_player(char c)
{
	return (c == 'N' || c == 'S' || c == 'W' || c == 'E');
}

t_point2d	get_angle_vector(double angle)
{
	double	dx;
	double	dy;

	dx = cos(angle);
	dy = sin(angle);
	if (fabs(dx) < 1e-10)
		dx = 0;
	if (fabs(dy) < 1e-10)
		dy = 0;
	return (new_point2d(dx, dy));
}

double	init_player_angle(t_directions dir)
{
	if (dir == NORTH)
		return (M_PI / 2);
	if (dir == SOUTH)
		return ((M_PI * 3) / 2);
	if (dir == WEST)
		return (M_PI);
	if (dir == EAST)
		return (0);
	return (M_PI / 2);
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
