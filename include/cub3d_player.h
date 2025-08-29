/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_player.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 11:05:04 by fdeleard          #+#    #+#             */
/*   Updated: 2025/08/28 19:14:37 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_PLAYER_H
# define CUB3D_PLAYER_H

# include <stdbool.h>
# include "cub3d_render.h"

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
	t_dpoint2d		pos;
	t_dpoint2d		dir;
	t_dpoint2d		plane;
}	t_player;

/* UTILS FUNCTIONS */
bool			is_player(char c);
char			*get_player_direction_str(t_directions dir);
t_dpoint2d		init_player_dir(t_directions dir);
t_directions	get_player_direction(char c);

#endif
