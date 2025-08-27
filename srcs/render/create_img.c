/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 13:37:19 by fdeleard          #+#    #+#             */
/*   Updated: 2025/08/27 12:20:38 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "mlx.h"
#include "cub3d.h"
#include "cub3d_render.h"

void	create_minimap_img(t_cub3d *p)
{
	if (p->minimap.img_ptr)
		mlx_destroy_image(p->mlx_ptr, p->minimap.img_ptr);
	p->minimap.img_ptr = NULL;
	p->minimap.width = 300;
	p->minimap.height = 300;
	p->minimap.img_ptr = mlx_new_image(p->mlx_ptr, 300, 300);
	if (!p->minimap.img_ptr)
	{
		printf("Failed to create minimap\n");
		free_cub3d(p);
		exit(1);
	}
	p->minimap.addr = mlx_get_data_addr(p->minimap.img_ptr, \
			&p->minimap.bits_per_pixel, &p->minimap.line_lenght, \
			&p->minimap.endian);
	if (!p->minimap.addr)
	{
		printf("Failed to get minimap data\n");
		free_cub3d(p);
		exit(1);
	}
	draw_map(&p->minimap, &p->map);
	draw_player(&p->minimap, &p->map);
}
void	create_raycast_img(t_cub3d *p)
{
	if (p->raycast.img_ptr)
		mlx_destroy_image(p->mlx_ptr, p->raycast.img_ptr);
	p->raycast.img_ptr = NULL;
	p->raycast.width = 1920;
	p->raycast.height = 1080;
	p->raycast.img_ptr = mlx_new_image(p->mlx_ptr, 1920, 1080);
	if (!p->raycast.img_ptr)
	{
		printf("Failed to create raycast\n");
		free_cub3d(p);
		exit(1);
	}
	p->raycast.addr = mlx_get_data_addr(p->raycast.img_ptr, \
			&p->raycast.bits_per_pixel, &p->raycast.line_lenght, \
			&p->raycast.endian);
	if (!p->raycast.addr)
	{
		printf("Failed to get raycast data\n");
		free_cub3d(p);
		exit(1);
	}
	raycast(&p->raycast, &p->map);
}

