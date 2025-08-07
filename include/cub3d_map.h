/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_map.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 11:01:31 by fdeleard          #+#    #+#             */
/*   Updated: 2025/08/07 12:58:38 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_MAP_H
# define CUB3D_MAP_H

# include <stdbool.h>

# include "cub3d_colors.h"
# include "cub3d_texture.h"
# include "cub3d_player.h"

typedef struct s_map_info
{
	bool	has_player;
	bool	is_closed;
}	t_map_info;

typedef struct s_map
{
	int				fd;
	char			**map;
	t_rgb			ceiling;
	t_rgb			floor;
	t_player		player;
	t_textures		textures;
}	t_map;

#endif
