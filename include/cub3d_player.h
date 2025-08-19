/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_player.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 11:05:04 by fdeleard          #+#    #+#             */
/*   Updated: 2025/08/19 10:25:42 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_PLAYER_H
# define CUB3D_PLAYER_H

#include <stdbool.h>

typedef enum e_directions
{
	NORTH,
	SOUTH,
	EAST,
	WEST,
}	t_directions;

typedef struct s_player
{
	t_directions	player_direction;
	int				x;
	int				y;
}	t_player;

/* UTILS FUNCTIONS */
bool	is_player(char c);

#endif
