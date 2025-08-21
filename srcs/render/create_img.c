/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 13:37:19 by fdeleard          #+#    #+#             */
/*   Updated: 2025/08/21 14:03:05 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "mlx.h"
#include "cub3d.h"
#include "cub3d_render.h"

void	create_img(t_cub3d *p)
{
	p->img.width = 1920;
	p->img.height = 1080;
	p->img.img_ptr = mlx_new_image(p->mlx_ptr, 1920, 1080);
	if (!p->img.img_ptr)
	{
		printf("Failed to create img\n");
		free_cub3d(p);
		exit(1);
	}
	p->img.addr = mlx_get_data_addr(p->img.img_ptr, &p->img.bits_per_pixel, \
			&p->img.line_lenght, &p->img.endian);
	if (!p->img.addr)
	{
		printf("Failed to get img data\n");
		free_cub3d(p);
		exit(1);
	}
}
