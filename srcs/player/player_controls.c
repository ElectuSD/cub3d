/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_controls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucnavar <lucnavar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 16:26:30 by lucnavar          #+#    #+#             */
/*   Updated: 2025/10/06 10:41:07 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_input.h"
#include "cub3d_player.h"

static void	update_player_rotation(t_player *p, int *keystate);
static void	update_minimap_scale(t_img *minimap, int *keystate);
static void	update_player_speed(t_player *p, int *keystate, double dt);
static void	update_player_position(t_player *p, t_map *map, int *keystate);

int	update_player(t_cub3d *p, double dt)
{
	t_player	*player;

	player = &p->map.player;
	update_player_speed(player, player->keystate, dt);
	update_player_position(player, &p->map, player->keystate);
	update_player_rotation(player, player->keystate);
	update_minimap_scale(&p->minimap, player->keystate);
	return (0);
}

static void	update_player_speed(t_player *p, int *keystate, double dt)
{
	double		speed_multiplier;

	speed_multiplier = 1.0;
	if (is_key_pressed(LEFT_SHIFT, keystate))
		speed_multiplier = 2.0;
	p->move_speed = MOVE_SPEED * dt * speed_multiplier;
	p->rot_speed = ROT_SPEED * dt;
}

static void	update_player_position(t_player *p, t_map *map, int *keystate)
{
	if (is_key_pressed(W_KEY, keystate))
		move_up(p->move_speed, map, &p->pos, &p->dir);
	if (is_key_pressed(S_KEY, keystate))
		move_down(p->move_speed, map, &p->pos, &p->dir);
	if (is_key_pressed(A_KEY, keystate))
		move_left(p->move_speed, map, &p->pos, &p->plane);
	if (is_key_pressed(D_KEY, keystate))
		move_right(p->move_speed, map, &p->pos, &p->plane);
}

static void	update_player_rotation(t_player *p, int *keystate)
{
	if (is_key_pressed(LEFT_ARROW, keystate))
		rotate_left(p->rot_speed, &p->dir, &p->plane);
	if (is_key_pressed(RIGHT_ARROW, keystate))
		rotate_right(p->rot_speed, &p->dir, &p->plane);
}

static void	update_minimap_scale(t_img *minimap, int *keystate)
{
	if (is_key_pressed(PLUS_KEY, keystate))
	{

		if (minimap->scale >= 128)
			minimap->scale = 128;
		else
			minimap->scale++;
	}
	if (is_key_pressed(MINUS_KEY, keystate))
	{
		if (minimap->scale <= 16)
			minimap->scale = 16;
		else
			minimap->scale--;
	}
}
