/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 10:49:45 by fdeleard          #+#    #+#             */
/*   Updated: 2025/08/29 11:25:22 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_map.h>
#include "cub3d_raycast.h"

void	draw_raycast(t_img *img, t_map *map)
{
	t_raycast_drawing	rd;
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
		init_raycast_drawing(&rd, &r, x, img->height);
		get_wall_texture(map, &r, &rd);
		draw_texture_on_img(img, &rd, &r);
		x++;
	}
}

void	init_raycast(t_img *img, t_map *map, t_raycast *r, int x)
{
	r->camerax = 2.0 * x / img->width - 1;
	r->v_ray_start = map->player.pos;
	r->v_ray_dir = get_ray_dir(map->player.dir, map->player.plane, r->camerax);
	r->v_ray_unit_step_size = get_ray_unit_step_size(r->v_ray_dir);
	r->v_map_check = convert_dpoint2d_to_ipoint2d(r->v_ray_start);
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
