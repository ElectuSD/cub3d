/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_map.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <fdeleard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 01:55:18 by fdeleard          #+#    #+#             */
/*   Updated: 2025/10/05 03:55:22 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_MAP_H
# define CUB3D_MAP_H

# include <stdlib.h>

# include "cub3d_colors.h"
# include "cub3d_player.h"
# include "cub3d_textures.h"

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

/* INIT MAP */
void	get_map_infos(t_map *map);

/* MAP CHECKING FUNCTIONS */
bool	is_in_map(t_map *map, t_dpoint2d v_ray_start);

/* MAP WALL CHECKING FUNCTIONS */
bool	is_wall(char c);
bool	has_hit_wall(char **map, t_ipoint2d v_map_check);

#endif // !CUB3D_MAP_H
