/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_draw.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <fdeleard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 01:54:05 by fdeleard          #+#    #+#             */
/*   Updated: 2025/10/06 10:39:03 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_DRAW_H
# define CUB3D_DRAW_H

# include <stdbool.h>

# include "cub3d_maths.h"

# define MAP_WIDTH 300
# define MAP_HEIGHT 300

# define MINIMAP_CELL_COLOR 0x000000
# define MINIMAP_GRID_COLOR 0x696969
# define MINIMAP_WALL_COLOR 0xFFFFFF

# define MINIMAP_SCALE 32

# define CROSSHAIR_COLOR 0xFF0000

typedef struct s_map	t_map;
typedef struct s_cub3d	t_cub3d;

typedef struct s_img
{
	void			*img_ptr;
	char			*addr;
	int				bits_per_pixel;
	int				bytes_per_pixel;
	int				line_lenght;
	int				endian;
	int				height;
	int				width;
	unsigned int	scale;
	t_dpoint2d		pos;
}	t_img;

typedef struct s_line
{
	double			dx;
	int				sx;
	double			dy;
	int				sy;
	double			err;
	int				e2;
	int				color;
}	t_line;

/* CREATE IMGS */
bool	create_img(t_cub3d *p);
void	create_raycast_img(t_cub3d *p);
void	create_minimap_img(t_cub3d *p);

/* DRAWING FUNCTIONS */
void	draw_pixel(t_img *data, int x, int y, int color);
void	draw_line(t_img *img, t_ipoint2d p1, t_ipoint2d p2, int color);
void	draw_floor(t_img *img, int color);
void	draw_ceiling(t_img *img, int color);
void	draw_raycast(t_img *img, t_map *map);
void	draw_crosshair(t_img *img, int color);
void	draw_minimap(t_img *minimap, t_img *raycast, t_map *map);
void	draw_rectangle(t_img *img, t_ipoint2d a, t_ipoint2d b, int color);
void	draw_rectangle_fill(t_img *img, t_ipoint2d a, t_ipoint2d b, int color);

/* DRAWING MINIMAP UTILS FUNCTIONS */
void	draw_grid(t_img *img, t_map *map);
void	draw_player(t_img *img, t_map *map);

#endif // !CUB3D_DRAW_H
