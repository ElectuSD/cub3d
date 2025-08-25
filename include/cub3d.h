/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 10:30:49 by fdeleard          #+#    #+#             */
/*   Updated: 2025/08/22 13:47:48 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "cub3d_map.h" 
# include "cub3d_render.h" 

typedef struct s_cub3d
{
	bool		is_updated;
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		img;
	t_map		map;
}	t_cub3d;

/* PRINTING FUNCTION FOR DEBUG */
void	print_map_infos(t_map *map);

/* FREE FUNCTIONS */
void	free_map(t_map *map);
void	free_cub3d(t_cub3d *p);
void	free_textures(t_textures *textures);
void	destroy_mlx_ptrs(void **win_ptr, void **img_ptr, void **mlx_ptr);

#endif
