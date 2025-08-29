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
#include <unistd.h>
#include <sys/time.h>

#include "mlx.h"
#include "cub3d.h"

long long	get_current_us(void);

int	update_loop(void *params)
{
	static long long	oldTime = 0;
	long long			start, end;
	long long			elapsed;
	double				frametime;
	t_cub3d				*p;


	p = params;
	start = get_current_us();
	if (!p->is_updated)
	{
		//printf("NEW IMAGE CREATED\n");
		draw_map(&p->minimap, &p->map);
		draw_player(&p->minimap, &p->map);
		draw_floor(&p->raycast, &p->map);
		draw_ceiling(&p->raycast, &p->map);
		draw_raycast(&p->raycast, &p->map);
		mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->raycast.img_ptr, 0, 0);
		mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->minimap.img_ptr, 0, 0);
		p->is_updated = true;
	}
	end = get_current_us();
	if (oldTime != 0)
	{
		frametime = (start - oldTime) / 1000000.0;
		printf("FRAME %f\n", 1.0 / frametime);
		elapsed = end - start;
		if (elapsed < 1000000 / 240)
			usleep(1000000 / 240 - elapsed);
	}
	oldTime = start;
	return (0);
}

long long	get_current_us(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000000LL + tv.tv_usec);
}
