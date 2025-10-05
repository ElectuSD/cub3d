/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_input.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <fdeleard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 02:02:16 by fdeleard          #+#    #+#             */
/*   Updated: 2025/10/05 03:54:13 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_INPUT_H
# define CUB3D_INPUT_H

# include <stdbool.h>

# define MAX_KEYS 256

typedef struct s_cub3d	t_cub3d;

enum e_keycodes
{
	ON_KEYDOWN				= 2,
	ON_KEYUP				= 3,
	ON_BUTTON_PRESS			= 4,
	ON_BUTTON_RELEASE		= 5,
	ON_MOTION_NOTIFY		= 6,
	ON_DESTROY				= 17,
	A_KEY					= 97,
	D_KEY					= 100,
	E_KEY					= 101,
	Q_KEY					= 113,
	S_KEY					= 115,
	W_KEY					= 119,
	ESC_KEY					= 65307,
	LEFT_ARROW				= 65361,
	UP_ARROW				= 65362,
	RIGHT_ARROW				= 65363,
	DOWN_ARROW				= 65364,
	LEFT_SHIFT				= 65505,
};

/* HOOK EVENTS */
void	hook_events(t_cub3d *p);

/* CHECKS IF KEY IS BEING PRESSED BY PLAYER */
bool	is_key_pressed(int key, int *keystate);

#endif // !CUB3D_INPUT_H
