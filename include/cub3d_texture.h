/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_texture.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 10:27:47 by fdeleard          #+#    #+#             */
/*   Updated: 2025/08/27 13:26:16 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_TEXTURE_H
# define CUB3D_TEXTURE_H

# include <stdbool.h>
# include "cub3d_render.h"

typedef struct s_cub3d	t_cub3d;
typedef struct s_map	t_map;

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

/* LOAD TEXTURE IMGS */
bool	load_textures(t_cub3d *p, t_map *map);

#endif
