/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_map.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 11:01:31 by fdeleard          #+#    #+#             */
/*   Updated: 2025/08/27 13:03:24 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_MAP_H
# define CUB3D_MAP_H

# include <stdlib.h>
# include <stdbool.h>

# include "cub3d_colors.h"
# include "cub3d_player.h"
# include "cub3d_texture.h"

typedef struct s_map_info
{
	bool	has_player;
	bool	is_closed;
}	t_map_info;

typedef struct s_map
{
	int				fd;
	char			**map;
	size_t			rows;
	size_t			cols;
	t_rgb			ceiling;
	t_rgb			floor;
	t_player		player;
	t_textures		textures;
}	t_map;

/* GET MAP ROWS SIZE */
size_t	get_map_size(char **map);

#endif
