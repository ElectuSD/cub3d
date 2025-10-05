/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <fdeleard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 03:28:54 by fdeleard          #+#    #+#             */
/*   Updated: 2025/10/05 03:29:18 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cub3d.h"

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

static void	load_north(t_cub3d *p, t_map *map)
{
	map->textures.n.img_ptr = mlx_xpm_file_to_image(p->mlx_ptr,
			map->textures.north, &map->textures.n.width,
			&map->textures.n.height);
	if (!map->textures.n.img_ptr)
		return ;
	map->textures.n.addr = mlx_get_data_addr(map->textures.n.img_ptr,
			&map->textures.n.bits_per_pixel, &map->textures.n.line_lenght,
			&map->textures.n.endian);
	map->textures.n.bytes_per_pixel = map->textures.n.bits_per_pixel / 8;
}

static void	load_south(t_cub3d *p, t_map *map)
{
	map->textures.s.img_ptr = mlx_xpm_file_to_image(p->mlx_ptr,
			map->textures.south, &map->textures.s.width,
			&map->textures.s.height);
	if (!map->textures.s.img_ptr)
		return ;
	map->textures.s.addr = mlx_get_data_addr(map->textures.s.img_ptr,
			&map->textures.s.bits_per_pixel, &map->textures.s.line_lenght,
			&map->textures.s.endian);
	map->textures.s.bytes_per_pixel = map->textures.s.bits_per_pixel / 8;
}

static void	load_west(t_cub3d *p, t_map *map)
{
	map->textures.w.img_ptr = mlx_xpm_file_to_image(p->mlx_ptr,
			map->textures.west, &map->textures.w.width,
			&map->textures.w.height);
	if (!map->textures.w.img_ptr)
		return ;
	map->textures.w.addr = mlx_get_data_addr(map->textures.w.img_ptr,
			&map->textures.w.bits_per_pixel, &map->textures.w.line_lenght,
			&map->textures.w.endian);
	map->textures.w.bytes_per_pixel = map->textures.w.bits_per_pixel / 8;
}

static void	load_east(t_cub3d *p, t_map *map)
{
	map->textures.e.img_ptr = mlx_xpm_file_to_image(p->mlx_ptr,
			map->textures.east, &map->textures.e.width,
			&map->textures.e.height);
	if (!map->textures.e.img_ptr)
		return ;
	map->textures.e.addr = mlx_get_data_addr(map->textures.e.img_ptr,
			&map->textures.e.bits_per_pixel, &map->textures.e.line_lenght,
			&map->textures.e.endian);
	map->textures.e.bytes_per_pixel = map->textures.e.bits_per_pixel / 8;
}
