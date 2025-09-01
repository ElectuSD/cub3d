/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_minimap_utils.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucnavar <lucnavar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 14:22:30 by lucnavar          #+#    #+#             */
/*   Updated: 2025/09/01 15:06:37 by lucnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_MINIMAP_UTILS_H
# define CUB3D_MINIMAP_UTILS_H

# include "cub3d_map.h"

bool		is_map_part(char c);
void		draw_grid_cell(t_img *img, int screen_x, int screen_y, int scale);
void		draw_grid_row(t_img *img, t_map *map, size_t i, double *offsets);
void		draw_wall(t_img *img, t_map *map, size_t i, size_t j);
void		draw_map_row(t_img *img, t_map *map, size_t i);

t_ipoint2d	map_to_screen_coords(t_img *img, t_map *map, double map_x,
				double map_y);

#endif
