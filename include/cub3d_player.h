/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_player.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <fdeleard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 01:59:25 by fdeleard          #+#    #+#             */
/*   Updated: 2025/10/05 04:04:04 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_PLAYER_H
# define CUB3D_PLAYER_H

# include <stdbool.h>

# include "cub3d_maths.h"
# include "cub3d_input.h"

# define PLANE_DEFAULT 0.66
# define MOVE_SPEED 3.0
# define ROT_SPEED 2.0

typedef struct s_map	t_map;

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

/* UPDATE PLAYER POSITION */
int			update_player(t_cub3d *p, double dt);

/* MOVE PLAYER */
void		move_up(double ms, t_map *m, t_dpoint2d *pos, t_dpoint2d *dir);
void		move_down(double ms, t_map *m, t_dpoint2d *pos, t_dpoint2d *dir);
void		move_left(double ms, t_map *m, t_dpoint2d *pos, t_dpoint2d *plane);
void		move_right(double ms, t_map *m, t_dpoint2d *pos, t_dpoint2d *plane);

/* ROTATE PLAYER */
void		rotate_left(double rs, t_dpoint2d *dir, t_dpoint2d *plane);
void		rotate_right(double rs, t_dpoint2d *dir, t_dpoint2d *plane);

/* SET PLAYERS INFOS */
void		set_player_infos(t_player *player, char c, int x, int y);

/* UTILS FUNCTIONS */
bool		is_player(char c);
t_dirs		get_player_direction(char c);
t_dpoint2d	init_player_dir(t_dirs dir);
t_dpoint2d	init_player_plane(t_dirs dir);

#endif
