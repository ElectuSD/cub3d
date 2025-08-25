/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_render.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 11:01:50 by fdeleard          #+#    #+#             */
/*   Updated: 2025/08/25 11:18:43 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_RENDER_H
# define CUB3D_RENDER_H

# include <stdbool.h>

typedef struct s_cub3d	t_cub3d;
typedef struct s_map	t_map;

enum e_keycodes
{
	ON_KEYDOWN				= 2,
	ON_KEYUP				= 3,
	ON_BUTTON_PRESS			= 4,
	ON_BUTTON_RELEASE		= 5,
	ON_MOTION_NOTIFY		= 6,
	ON_DESTROY				= 17,
	ESC_KEY					= 65307,
	LEFT					= 65361,
	UP						= 65362,
	RIGHT					= 65363,
	DOWN					= 65364,
};

typedef struct s_point3d
{
	double	x;
	double	y;
	double	z;
}	t_point3d;

typedef struct s_point2d
{
	double	x;
	double	y;
}	t_point2d;

typedef struct s_rec
{
	t_point2d	tl;
	t_point2d	br;
}	t_rec;

typedef struct s_line
{
	double		dx;
	int			sx;
	double		dy;
	int			sy;
	double		err;
	double		e2;
	int			color;
}	t_line;

typedef struct s_img
{
	void		*img_ptr;
	char		*addr;
	int			bits_per_pixel;
	int			line_lenght;
	int			endian;
	int			height;
	int			width;
	t_point2d	pos;
}	t_img;

/* RENDER LOOP FUNCTION */
int			update_loop(void *params);

/* RAYCAST PROTOTYPE FUNCTIOM */
void		raycast(t_img *img, t_map *map);

/* CREATE SINGLE IMG*/
void		create_img(t_cub3d *p);

/* INIT MLX_PTR AND WIN_PTR */
bool		init_mlx(t_cub3d *p);

/* HOOK EVENTS FUNCTION */
void		hook_events(t_cub3d *p);

/* DRAWS PIXEL IN IMG*/
void		ft_mlx_pixel_put(t_img *data, int x, int y, int color);

/* DRAW LINE FUNCTION USING BRESENHAM ALGORITHM */
void		draw_line(t_img *img, t_point2d p1, t_point2d p2, int color);

/* DRAW RECTANGLE USING DRAW LINE FUNCTION */
void		draw_rectangle(t_img *img, t_point2d a, t_point2d b, int color);
void		draw_rectangle_fill(t_img *img, t_point2d a, t_point2d b, int c);

/* DRAW MAP USIGN DRAW RECTANGLE */
void		draw_map(t_img *img, t_map *map);

/* DRAW PLAYER FUNCTION */
void		draw_player(t_img *img, t_map *map);

/* CREATE STRUCTURES UTILS FUNCTIONS */
t_point2d	new_point2d(double x, double y);
t_rec		new_rectangle(t_point2d top_left, t_point2d bottom_right);

/* MATH UTILS FUNCTIONS */
double		min(double a, double b);
double		max(double a, double b);

#endif
