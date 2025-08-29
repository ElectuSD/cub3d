/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_raycast.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 10:58:33 by fdeleard          #+#    #+#             */
/*   Updated: 2025/08/29 13:55:35 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_RAYCAST_H
# define CUB3D_RAYCAST_H 

# include "cub3d_render.h"

typedef struct s_raycast
{
	int			hit_side;
	double		camerax;
	t_dpoint2d	v_step;
	t_dpoint2d	v_ray_dir;
	t_dpoint2d	v_ray_start;
	t_ipoint2d	v_map_check;
	t_dpoint2d	v_ray_lenght_1d;
	t_dpoint2d	v_ray_unit_step_size;
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
void		init_raycast(t_img *img, t_map *map, t_raycast *r, int x);
void		init_raycast_drawing(t_raycast_drawing *rd, t_raycast *r,
				int x, int height);

/* DRAWS RAYCAST RESULTS ON IMG*/
void		draw_texture_on_img(t_img *img, t_raycast_drawing *rd,
				t_raycast *r);

/* RAYCAST CALCULATIONS FUNCTIONS */
void		search_for_wall(char **map, t_raycast *r);
void		calculate_step_and_ray_lenght_1d(t_raycast *r);

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

/* CHECKS MAP BOUNDARIES */
bool		is_in_map(t_map *map, t_dpoint2d v_ray_start);
bool		is_east_or_north(int side, t_dpoint2d v_ray_dir);
bool		has_hit_wall(char **map, t_ipoint2d v_map_check);

#endif
