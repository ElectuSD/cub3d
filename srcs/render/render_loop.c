/* *********************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 13:51:45 by fdeleard          #+#    #+#             */
/*   Updated: 2025/08/26 11:31:25 by fdeleard         ###   ########.fr       */
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
		draw_map(&p->minimap, &p->map);
		draw_player(&p->minimap, &p->map);
		raycast(&p->raycast, &p->map);
		mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->raycast.img_ptr, 0, 0);
		mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->minimap.img_ptr, 0, 0);
		p->is_updated = true;
	}
	return (0);
}
