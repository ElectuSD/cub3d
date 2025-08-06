/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_player.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 11:05:04 by fdeleard          #+#    #+#             */
/*   Updated: 2025/08/06 11:06:06 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_PLAYER_H
# define CUB3D_PLAYER_H

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

#endif
