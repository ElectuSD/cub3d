/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_textures.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <fdeleard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 02:05:02 by fdeleard          #+#    #+#             */
/*   Updated: 2025/10/05 03:30:39 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_TEXTURES_H
# define CUB3D_TEXTURES_H

# include <stdbool.h>

# include "cub3d_draw.h"

typedef struct s_cub3d	t_cub3d;

typedef struct s_textures
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	t_img	n;
	t_img	s;
	t_img	w;
	t_img	e;
}	t_textures;

/* LOAD TEXTURES */
bool	load_textures(t_cub3d *p, t_map *map);

#endif // !CUB3D_TEXTURES_H
