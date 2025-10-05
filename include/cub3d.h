/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <fdeleard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 01:52:34 by fdeleard          #+#    #+#             */
/*   Updated: 2025/10/05 03:54:49 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "cub3d_map.h"
# include "cub3d_draw.h"

# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080

typedef struct s_cub3d
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_img			minimap;
	t_img			raycast;
	t_map			map;
	struct timeval	frametime;
}	t_cub3d;

/* INIT CUB3D */
bool	init_cub3d(t_cub3d *p, char *filename);
bool	init_mlx(t_cub3d *p);

/* FREE FUNCTIONS */
void	free_map(t_cub3d *p);
void	free_cub3d(t_cub3d	*p);
int		free_cub3d_and_exit(void *params);
void	free_textures(void *mlx_ptr, t_textures *textures);
void	destroy_mlx_ptrs(void **win_ptr, void **raycast_ptr,
			void **minimap_ptr, void **mlx_ptr);

#endif
