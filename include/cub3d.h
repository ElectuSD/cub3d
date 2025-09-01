/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 10:30:49 by fdeleard          #+#    #+#             */
/*   Updated: 2025/09/01 11:02:05 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "cub3d_map.h" 
# include "cub3d_render.h" 

# define FPS 240

typedef struct s_cub3d
{
	bool			is_updated;
	void			*mlx_ptr;
	void			*win_ptr;
	t_img			minimap;
	t_img			raycast;
	t_map			map;
	struct timeval	frametime;
}	t_cub3d;

/* PRINTING FUNCTION FOR DEBUG */
void	print_map_infos(t_map *map);

/* FREE FUNCTIONS */
int		free_cub3d_and_exit(void *params);
void	free_cub3d(t_cub3d	*p);
void	free_map(t_cub3d *p);
void	free_textures(void *mlx_ptr, t_textures *textures);
void	destroy_mlx_ptrs(void **win_ptr, void **raycast_ptr,
			void **minimap_ptr, void **mlx_ptr);

#endif
