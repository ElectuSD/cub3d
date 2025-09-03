/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_render.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucnavar <lucnavar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 11:01:50 by fdeleard          #+#    #+#             */
/*   Updated: 2025/09/03 09:43:05 by lucnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_RENDER_H
# define CUB3D_RENDER_H

# include <stdbool.h>

typedef struct s_cub3d	t_cub3d;
typedef struct s_map	t_map;

# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080
# define MAP_WIDTH 300
# define MAP_HEIGHT 300

# define PLANE_DEFAULT 0.66

# define MAX_KEYS 256

enum e_keycodes
{
	ON_KEYDOWN				= 2,
	ON_KEYUP				= 3,
	ON_BUTTON_PRESS			= 4,
	ON_BUTTON_RELEASE		= 5,
	ON_MOTION_NOTIFY		= 6,
	ON_DESTROY				= 17,
	A_KEY					= 97,
	D_KEY					= 100,
	E_KEY					= 101,
	Q_KEY					= 113,
	S_KEY					= 115,
	W_KEY					= 119,
	ESC_KEY					= 65307,
	LEFT_ARROW				= 65361,
	UP_ARROW				= 65362,
	RIGHT_ARROW				= 65363,
	DOWN_ARROW				= 65364,
	LEFT_SHIFT				= 65505,
};

typedef struct s_dpoint2d
{
	double	x;
	double	y;
}	t_dpoint2d;

typedef struct s_ipoint2d
{
	int		x;
	int		y;
}	t_ipoint2d;

typedef struct s_rec
{
	t_ipoint2d	tl;
	t_ipoint2d	br;
}	t_rec;

typedef struct s_line
{
	double		dx;
	int			sx;
	double		dy;
	int			sy;
	double		err;
	int			e2;
	int			color;
}	t_line;

typedef struct s_img
{
	void		*img_ptr;
	char		*addr;
	int			bits_per_pixel;
	int			bytes_per_pixel;
	int			line_lenght;
	int			endian;
	int			height;
	int			width;
	int			scale;
	t_dpoint2d	pos;
}	t_img;

/* RENDER LOOP FUNCTION */
int					update_loop(void *params);

/* CREATE SINGLE IMG*/
void				create_minimap_img(t_cub3d *p);
void				create_raycast_img(t_cub3d *p);

/* INIT MLX_PTR AND WIN_PTR */
bool				init_mlx(t_cub3d *p);

/* DRAW FUNCTIONS */
void				draw_pixel(t_img *data, int x, int y, int color);
void				draw_map(t_img *img, t_map *map);
void				draw_floor(t_img *img, t_map *map);
void				draw_player(t_img *img, t_map *map);
void				draw_raycast(t_img *img, t_map *map);
void				draw_ceiling(t_img *img, t_map *map);
void				draw_line(t_img *img, t_ipoint2d p1, t_ipoint2d p2,
						int color);
void				draw_rectangle(t_img *img, t_ipoint2d a, t_ipoint2d b,
						int color);
void				draw_rectangle_fill(t_img *img, t_ipoint2d a, t_ipoint2d b,
						int color);

/* HOOK EVENTS FUNCTION */
void				hook_events(t_cub3d *p);
bool				is_key_pressed(int key, int *keystate);

/* CREATE STRUCTURES UTILS FUNCTIONS */
t_rec				new_rectangle(t_ipoint2d top_left, t_ipoint2d bottom_right);
t_ipoint2d			new_ipoint2d(int x, int y);
t_dpoint2d			new_dpoint2d(double x, double y);
t_ipoint2d			convert_dpoint2d_to_ipoint2d(t_dpoint2d dpoint2d);

#endif
