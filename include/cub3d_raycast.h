/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_raycast.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <fdeleard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 02:08:05 by fdeleard          #+#    #+#             */
/*   Updated: 2025/10/05 03:25:33 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_RAYCAST_H
# define CUB3D_RAYCAST_H

# include <stdbool.h>

# include "cub3d_draw.h"
# include "cub3d_maths.h"

typedef struct s_raycast
{
	int			hit_side;
	double		camerax;
	t_dpoint2d	step;
	t_dpoint2d	raydir;
	t_dpoint2d	raystart;
	t_ipoint2d	mapcheck;
	t_dpoint2d	raylenght;
	t_dpoint2d	rayunitss;
}	t_raycast;

typedef struct s_raycast_drawing
{
	int			x;
	int			color;
	int			line_height;
	int			draw_start;
	int			draw_end;
	t_img		texture;
	double		step;
	double		wall_x;
	double		texture_pos;
	double		perp_wall_dist;
	t_ipoint2d	texture_coord;
}	t_raycast_drawing;

/* INIT RAYCASTING */
void		init_raycast_drawing(t_raycast_drawing *rd, t_raycast *r,
				int x, int height);

/* DRAWS RAYCAST RESULTS ON IMG*/
void		draw_texture_on_img(t_img *img, t_raycast_drawing *rd,
				t_raycast *r);

/* RAYCAST GETTERS */
int			get_color_on_img(t_img *img, int x, int y);
void		get_wall_texture(t_map *map, t_raycast *r, t_raycast_drawing *rd);
double		get_perp_wall_dist(t_dpoint2d v_ray_lenght_1d,
				t_dpoint2d v_ray_unit_step_size, int side);
t_dpoint2d	get_ray_unit_step_size(t_dpoint2d v_ray_dir);
t_dpoint2d	get_ray_dir(t_dpoint2d dir, t_dpoint2d plane, double camerax);

/* RAYCAST SETTERS */
void		set_drawing_textures(t_img *img, t_raycast_drawing *rd,
				t_raycast *r);
double		set_pos_dir_ray_lenght(double ray_start, double map_check,
				double ray_unit_step_size);
double		set_neg_dir_ray_lenght(double ray_start, double map_check,
				double ray_unit_step_size);

/* CHECK HIT SIDE */
bool		is_east_or_north(int side, t_dpoint2d v_ray_dir);

#endif // !CUB3D_RAYCAST_H
