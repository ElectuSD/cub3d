/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <fdeleard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 03:56:38 by fdeleard          #+#    #+#             */
/*   Updated: 2025/10/06 01:02:20 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "mlx.h"
#include "cub3d.h"
#include "cub3d_draw.h"

void	create_minimap_img(t_cub3d *p)
{
	if (p->minimap.img_ptr)
		mlx_destroy_image(p->mlx_ptr, p->minimap.img_ptr);
	p->minimap.img_ptr = NULL;
	p->minimap.width = MAP_WIDTH;
	p->minimap.height = MAP_HEIGHT;
	p->minimap.img_ptr = mlx_new_image(p->mlx_ptr, MAP_WIDTH, MAP_HEIGHT);
	if (!p->minimap.img_ptr)
	{
		printf("Failed to create minimap\n");
		free_cub3d(p);
		exit(1);
	}
	p->minimap.addr = mlx_get_data_addr(p->minimap.img_ptr,
			&p->minimap.bits_per_pixel,
			&p->minimap.line_lenght, &p->minimap.endian);
	if (!p->minimap.addr)
	{
		printf("Failed to get minimap data\n");
		free_cub3d(p);
		exit(1);
	}
	p->minimap.scale = (p->minimap.width / p->map.cols) * 2;
	if (p->minimap.scale < 32)
		p->minimap.scale = 32;
	p->minimap.bytes_per_pixel = p->minimap.bits_per_pixel / 8;
}

void	create_raycast_img(t_cub3d *p)
{
	if (p->raycast.img_ptr)
		mlx_destroy_image(p->mlx_ptr, p->raycast.img_ptr);
	p->raycast.img_ptr = NULL;
	p->raycast.width = WIN_WIDTH;
	p->raycast.height = WIN_HEIGHT;
	p->raycast.img_ptr = mlx_new_image(p->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	if (!p->raycast.img_ptr)
	{
		printf("Failed to create raycast\n");
		free_cub3d(p);
		exit(1);
	}
	p->raycast.addr = mlx_get_data_addr(p->raycast.img_ptr,
			&p->raycast.bits_per_pixel,
			&p->raycast.line_lenght, &p->raycast.endian);
	if (!p->raycast.addr)
	{
		printf("Failed to get raycast data\n");
		free_cub3d(p);
		exit(1);
	}
	p->raycast.bytes_per_pixel = p->raycast.bits_per_pixel / 8;
}

bool	create_img(t_cub3d *p)
{
	if (load_textures(p, &p->map))
	{
		printf("Error\nFailed to load textures\n");
		return (false);
	}
	create_minimap_img(p);
	create_raycast_img(p);
	return (true);
}
