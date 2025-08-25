/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 13:51:45 by fdeleard          #+#    #+#             */
/*   Updated: 2025/08/22 13:54:10 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "mlx.h"
#include "cub3d.h"

int	update_loop(void *params)
{
	t_cub3d	*p;

	p = params;
	if (!p->is_updated)
	{
		printf("NEW IMAGE CREATED\n");
		create_img(p);
		draw_map(&p->img, &p->map);
		draw_player(&p->img, &p->map);
		mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->img.img_ptr, 0, 0);
		p->is_updated = true;
	}
	return (0);
}
