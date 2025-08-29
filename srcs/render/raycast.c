/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 10:49:45 by fdeleard          #+#    #+#             */
/*   Updated: 2025/08/28 20:16:43 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include <cub3d_map.h>
#include "cub3d_render.h"

bool	is_in_map(t_map *map, t_dpoint2d v_ray_start)
{
	return (!(v_ray_start.x < map->cols && v_ray_start.x >= 0 \
			&& v_ray_start.y < map->rows && v_ray_start.y >= 0
			&& map->map[(int)v_ray_start.y][(int)v_ray_start.x] == '1'));
}

bool	has_hit_wall(char **map, t_ipoint2d v_map_check)
{
	return (map[v_map_check.y][v_map_check.x] == '1');
}

double	get_perp_wall_dist(t_dpoint2d v_ray_lenght_1d,
			t_dpoint2d v_ray_unit_step_size, int side)
{
	if (side == 0)
		return (v_ray_lenght_1d.x - v_ray_unit_step_size.x);
	return (v_ray_lenght_1d.y - v_ray_unit_step_size.y);
}

t_ipoint2d	convert_dpoint2d_to_ipoint2d(t_dpoint2d dpoint2d)
{
	t_ipoint2d	new;

	new = new_ipoint2d(dpoint2d.x, dpoint2d.y);
	return (new);
}

t_dpoint2d	get_ray_dir(t_dpoint2d dir, t_dpoint2d plane, double camerax)
{
	return (new_dpoint2d(dir.x + plane.x * camerax, dir.y + plane.y * camerax));
}

t_dpoint2d	get_ray_unit_step_size(t_dpoint2d v_ray_dir)
{
	t_dpoint2d	v_ray_unit_step_size;

	if (v_ray_dir.x == 0)
		v_ray_unit_step_size.x = 1e30;
	else
		v_ray_unit_step_size.x = fabs(1 / v_ray_dir.x);
	if (v_ray_dir.y == 0)
		v_ray_unit_step_size.y = 1e30;
	else
		v_ray_unit_step_size.y = fabs(1 / v_ray_dir.y);
	return (v_ray_unit_step_size);
}

void	init_raycast(t_img *img, t_map *map, t_raycast *r, int x)
{
	r->camerax = 2.0 * x / img->width - 1;
	r->v_ray_start = map->player.pos;
	r->v_ray_dir = get_ray_dir(map->player.dir, map->player.plane, r->camerax);
	r->v_ray_unit_step_size = get_ray_unit_step_size(r->v_ray_dir);
	r->v_map_check = convert_dpoint2d_to_ipoint2d(r->v_ray_start);
}

void	init_raycast_drawing(t_raycast_drawing *rd, t_raycast *r, int height)
{
	rd->perp_wall_dist = get_perp_wall_dist(r->v_ray_lenght_1d, \
		r->v_ray_unit_step_size, r->hit_side);
	rd->line_height = height / rd->perp_wall_dist;
	rd->draw_start = -rd->line_height / 2 + height / 2;
	if (rd->draw_start < 0)
		rd->draw_start = 0;
	rd->draw_end = rd->line_height / 2 + height / 2;
	if (rd->draw_end >= height)
		rd->draw_end = height - 1;
}

double	set_neg_dir_ray_lenght(double ray_start, double map_check,
			double ray_unit_step_size)
{
	return ((ray_start - map_check) * ray_unit_step_size);
}

double	set_pos_dir_ray_lenght(double ray_start, double map_check,
			double ray_unit_step_size)
{
	return ((map_check + 1.0 - ray_start) * ray_unit_step_size);
}

void	calculate_step_and_ray_lenght_1d(t_raycast *r)
{
	if (r->v_ray_dir.x < 0)
	{
		r->v_step.x = -1;
		r->v_ray_lenght_1d.x = set_neg_dir_ray_lenght(r->v_ray_start.x, \
			r->v_map_check.x, r->v_ray_unit_step_size.x);
	}
	else
	{
		r->v_step.x = 1;
		r->v_ray_lenght_1d.x = set_pos_dir_ray_lenght(r->v_ray_start.x, \
			r->v_map_check.x, r->v_ray_unit_step_size.x);
	}
	if (r->v_ray_dir.y < 0)
	{
		r->v_step.y = -1;
		r->v_ray_lenght_1d.y = set_neg_dir_ray_lenght(r->v_ray_start.y, \
			r->v_map_check.y, r->v_ray_unit_step_size.y);
	}
	else
	{
		r->v_step.y = 1;
		r->v_ray_lenght_1d.y = set_pos_dir_ray_lenght(r->v_ray_start.y, \
			r->v_map_check.y, r->v_ray_unit_step_size.y);
	}
}

void	search_for_wall(char **map, t_raycast *r)
{
	bool	hit;

	hit = false;
	while (!hit)
	{
		if (r->v_ray_lenght_1d.x < r->v_ray_lenght_1d.y)
		{
			r->hit_side = 0;
			r->v_map_check.x += r->v_step.x;
			r->v_ray_lenght_1d.x += r->v_ray_unit_step_size.x;
		}
		else
		{
			r->hit_side = 1;
			r->v_map_check.y += r->v_step.y;
			r->v_ray_lenght_1d.y += r->v_ray_unit_step_size.y;
		}
		if (has_hit_wall(map, r->v_map_check))
			hit = true;
	}
}

void	draw_raycast(t_img *img, t_map *map)
{
	t_raycast_drawing	draw;
	t_raycast			r;
	int					x;

	x = 0;
	while (x < img->width)
	{
		init_raycast(img, map, &r, x);
		if (!is_in_map(map, r.v_ray_start))
			return ;
		calculate_step_and_ray_lenght_1d(&r);
		search_for_wall(map->map, &r);
		init_raycast_drawing(&draw, &r, img->height);

		double	wallX;
		t_img	texture;

		if (r.hit_side == 0)
		{
			if (r.v_ray_dir.x > 0)
				texture = map->textures.e;
			else
				texture = map->textures.w;
			wallX = map->player.pos.y + draw.perp_wall_dist * r.v_ray_dir.y;
		}
		else
		{
			if (r.v_ray_dir.y > 0)
				texture = map->textures.s;
			else
				texture = map->textures.n;
			wallX = map->player.pos.x + draw.perp_wall_dist * r.v_ray_dir.x;
		}
		wallX -= floor(wallX);

		int	texX = wallX * texture.width;

		if (r.hit_side == 0 && r.v_ray_dir.x > 0) texX = texture.width - texX - 1;
		if (r.hit_side == 1 && r.v_ray_dir.y < 0) texX = texture.width - texX - 1;

		double	step = 1.0 * texture.height / draw.line_height;
		double	texPos = (draw.draw_start - (img->height / 2.0) + (draw.line_height / 2.0)) * step;

		int	y;

		y = draw.draw_start;
		while (y < draw.draw_end)
		{
			int		texY = (int)texPos % (texture.height);
			texPos += step;
			int		color;
			char	*dst;
			dst = texture.addr + (texY * texture.line_lenght + texX * (texture.bits_per_pixel / 8));
			color = *(unsigned int *)dst;
			if (r.hit_side == 1) color = (color >> 1) & 8355711;
			draw_pixel(img, x, y, color);
			y++;
		}
		x++;
	}
}
