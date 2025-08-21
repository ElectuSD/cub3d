/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_render.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 11:01:50 by fdeleard          #+#    #+#             */
/*   Updated: 2025/08/21 11:08:24 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_RENDER_H
# define CUB3D_RENDER_H

# include <stdbool.h>

typedef struct s_cub3d	t_cub3d;

enum e_keycodes
{
	ON_BUTTON_PRESS			= 4,
	ON_BUTTON_RELEASE		= 5,
	ON_MOTION_NOTIFY		= 6,
	ON_DESTROY				= 17,
	ESC_KEY					= 65307,
	LEFT					= 65361,
	UP						= 65362,
	RIGHT					= 65363,
	DOWN					= 65364,
};

/* INIT MLX_PTR AND WIN_PTR */
bool	init_mlx(t_cub3d *p);

/* HOOK EVENTS FUNCTION */
void	hook_events(t_cub3d *p);

#endif
