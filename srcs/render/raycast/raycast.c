/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 10:49:45 by fdeleard          #+#    #+#             */
/*   Updated: 2025/09/02 20:42:29 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_map.h>
#include "cub3d_raycast.h"

static inline void	search_for_wall(char **map, t_raycast *r);
static inline void	calculate_step_and_ray_lenght_1d(t_raycast *r);
static inline void	init_raycast(t_img *img, t_map *map, t_raycast *r, int x);

void	draw_raycast(t_img *img, t_map *map)
{
	t_raycast_drawing	rd;
	t_raycast			r;
	int					x;

	x = 0;
	while (x < img->width)
	{
		init_raycast(img, map, &r, x);
		if (!is_in_map(map, r.raystart))
			return ;
		calculate_step_and_ray_lenght_1d(&r);
		search_for_wall(map->map, &r);
		init_raycast_drawing(&rd, &r, x, img->height);
		get_wall_texture(map, &r, &rd);
		draw_texture_on_img(img, &rd, &r);
		x++;
	}
}

static inline void	init_raycast(t_img *img, t_map *map, t_raycast *r, int x)
{
	r->camerax = 2.0 * x / img->width - 1;
	r->raystart = map->player.pos;
	r->raydir = get_ray_dir(map->player.dir, map->player.plane, r->camerax);
	r->rayunitss = get_ray_unit_step_size(r->raydir);
	r->mapcheck = convert_dpoint2d_to_ipoint2d(r->raystart);
}

static inline void	calculate_step_and_ray_lenght_1d(t_raycast *r)
{
	if (r->raydir.x < 0)
	{
		r->step.x = -1;
		r->raylenght.x = (r->raystart.x - r->mapcheck.x) * r->rayunitss.x;
	}
	else
	{
		r->step.x = 1;
		r->raylenght.x = (r->mapcheck.x + 1.0 - r->raystart.x) * r->rayunitss.x;
	}
	if (r->raydir.y < 0)
	{
		r->step.y = -1;
		r->raylenght.y = (r->raystart.y - r->mapcheck.y) * r->rayunitss.y;
	}
	else
	{
		r->step.y = 1;
		r->raylenght.y = (r->mapcheck.y + 1.0 - r->raystart.y) * r->rayunitss.y;
	}
}

static inline void	search_for_wall(char **map, t_raycast *r)
{
	while (!has_hit_wall(map, r->mapcheck))
	{
		if (r->raylenght.x < r->raylenght.y)
		{
			r->hit_side = 0;
			r->mapcheck.x += r->step.x;
			r->raylenght.x += r->rayunitss.x;
		}
		else
		{
			r->hit_side = 1;
			r->mapcheck.y += r->step.y;
			r->raylenght.y += r->rayunitss.y;
		}
	}
}
