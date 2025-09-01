/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_controls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucnavar <lucnavar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 16:26:30 by lucnavar          #+#    #+#             */
/*   Updated: 2025/09/01 16:26:30 by lucnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_player.h"
#include "cub3d.h"

int	update_player(t_cub3d *p, double dt)
{
	t_player	*player;
	double		speed_multiplier;

	player = &p->map.player;
	speed_multiplier = 1.0;
	if (is_key_pressed(LEFT_SHIFT, p->map.player.keystate))
		speed_multiplier = 2.0;
	player->move_speed = MOVE_SPEED * dt * speed_multiplier;
	player->rot_speed = ROT_SPEED * dt;
	if (is_key_pressed(W_KEY, p->map.player.keystate))
		move_up(player->move_speed, &p->map, &player->pos, &player->dir);
	if (is_key_pressed(S_KEY, p->map.player.keystate))
		move_down(player->move_speed, &p->map, &player->pos, &player->dir);
	if (is_key_pressed(A_KEY, p->map.player.keystate))
		move_left(player->move_speed, &p->map, &player->pos, &player->plane);
	if (is_key_pressed(D_KEY, p->map.player.keystate))
		move_right(player->move_speed, &p->map, &player->pos, &player->plane);
	if (is_key_pressed(LEFT_ARROW, p->map.player.keystate))
		rotate_left(player->rot_speed, &player->dir, &player->plane);
	if (is_key_pressed(RIGHT_ARROW, p->map.player.keystate))
		rotate_right(player->rot_speed, &player->dir, &player->plane);
	return (0);
}
