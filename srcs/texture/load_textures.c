/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 12:51:07 by fdeleard          #+#    #+#             */
/*   Updated: 2025/08/29 14:01:56 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

#include "cub3d.h"
#include "cub3d_render.h"
#include "cub3d_texture.h"

static void	load_north(t_cub3d *p, t_map *map);
static void	load_south(t_cub3d *p, t_map *map);
static void	load_west(t_cub3d *p, t_map *map);
static void	load_east(t_cub3d *p, t_map *map);

bool	load_textures(t_cub3d *p, t_map *map)
{
	load_north(p, map);
	load_south(p, map);
	load_west(p, map);
	load_east(p, map);
	return (!map->textures.n.img_ptr || !map->textures.s.img_ptr
		|| !map->textures.w.img_ptr || !map->textures.e.img_ptr);
}

static void	load_east(t_cub3d *p, t_map *map)
{
	map->textures.e.img_ptr = mlx_xpm_file_to_image(p->mlx_ptr,
			map->textures.east, &map->textures.e.width,
			&map->textures.e.height);
	map->textures.e.addr = mlx_get_data_addr(map->textures.e.img_ptr, \
			&map->textures.e.bits_per_pixel, &map->textures.e.line_lenght, \
			&map->textures.e.endian);
}

static void	load_west(t_cub3d *p, t_map *map)
{
	map->textures.w.img_ptr = mlx_xpm_file_to_image(p->mlx_ptr,
			map->textures.west, &map->textures.w.width,
			&map->textures.w.height);
	map->textures.w.addr = mlx_get_data_addr(map->textures.w.img_ptr, \
			&map->textures.w.bits_per_pixel, &map->textures.w.line_lenght, \
			&map->textures.w.endian);
}

static void	load_south(t_cub3d *p, t_map *map)
{
	map->textures.s.img_ptr = mlx_xpm_file_to_image(p->mlx_ptr,
			map->textures.south, &map->textures.s.width,
			&map->textures.s.height);
	map->textures.s.addr = mlx_get_data_addr(map->textures.s.img_ptr, \
			&map->textures.s.bits_per_pixel, &map->textures.s.line_lenght, \
			&map->textures.s.endian);
}

static void	load_north(t_cub3d *p, t_map *map)
{
	map->textures.n.img_ptr = mlx_xpm_file_to_image(p->mlx_ptr,
			map->textures.north, &map->textures.n.width,
			&map->textures.n.height);
	map->textures.n.addr = mlx_get_data_addr(map->textures.n.img_ptr, \
			&map->textures.n.bits_per_pixel, &map->textures.n.line_lenght, \
			&map->textures.n.endian);
}
