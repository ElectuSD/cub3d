/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_player.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 11:05:04 by fdeleard          #+#    #+#             */
/*   Updated: 2025/09/01 10:37:24 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_PLAYER_H
# define CUB3D_PLAYER_H

# include <stdbool.h>
# include "cub3d_render.h"

# define PLANE_DEFAULT 0.66

# define MOVE_SPEED 3.0
# define ROT_SPEED 2.0

typedef enum e_directions
{
	NORTH,
	SOUTH,
	EAST,
	WEST,
}	t_dirs;

typedef struct s_player
{
	int				keystate[MAX_KEYS];
	double			rot_speed;
	double			move_speed;
	t_dirs			player_direction;
	t_dpoint2d		pos;
	t_dpoint2d		dir;
	t_dpoint2d		plane;
}	t_player;

/* PLAYERS MOVEMENTS FUNCTIONS */
void		rotate_left(double rs, t_dpoint2d *dir, t_dpoint2d *plane);
void		rotate_right(double rs, t_dpoint2d *dir, t_dpoint2d *plane);
void		move_up(double ms, t_map *map, t_dpoint2d *pos, t_dpoint2d *dir);
void		move_down(double ms, t_map *map, t_dpoint2d *pos, t_dpoint2d *dir);

/* UTILS FUNCTIONS */
bool		is_player(char c);
void		set_player_infos(t_player *player, char c, int x, int y);
t_dirs		get_player_direction(char c);
t_dpoint2d	init_player_dir(t_dirs dir);
t_dpoint2d	init_player_plane(t_dirs dir);

#endif
