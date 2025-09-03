/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucnavar <lucnavar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 13:51:45 by fdeleard          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/09/01 16:24:11 by lucnavar         ###   ########.fr       */
=======
/*   Updated: 2025/09/02 16:29:57 by fdeleard         ###   ########.fr       */
>>>>>>> d8277b491d9752852a3f8ccad454c2be1cffd246
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx.h"

void	draw_minimap_on_raycast(t_img *raycast, t_img *minimap)
{
	int		x;
	int		y;
	int		color;
	char	*pixel;

	y = 0;
	while (y < minimap->height)
	{
		x = 0;
		while (x < minimap->width)
		{
			draw_pixel(raycast, x + 10, y + 10, 0x000000);
			x++;
		}
		y++;
	}
	y = 0;
	while (y < minimap->height)
	{
		x = 0;
		while (x < minimap->width)
		{
			pixel = minimap->addr + (y * minimap->line_lenght + x
					* minimap->bytes_per_pixel);
			color = *(int *)pixel;
			if (color != 0x000000)
				draw_pixel(raycast, x + 10, y + 10, color);
			x++;
		}
		y++;
	}
	double				dt;
	t_cub3d				*p;

	p = params;
	dt = get_delta_time(p);
	clear_img(&p->minimap, 0x696969);
	draw_map(&p->minimap, &p->map);
	draw_floor(&p->raycast, &p->map);
	draw_ceiling(&p->raycast, &p->map);
	draw_player(&p->minimap, &p->map);
	draw_raycast(&p->raycast, &p->map);
	update_player(p, dt);
	put_imgs_to_window(p, &p->raycast, &p->minimap);
	if (is_key_pressed(ESC_KEY, p->map.player.keystate))
		free_cub3d_and_exit(p);
	return (0);
}

static void	put_imgs_to_window(t_cub3d *p, t_img *raycast, t_img *minimap)
{
	mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, raycast->img_ptr, 0, 0);
	mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, minimap->img_ptr, 0, 0);
}

static void	clear_img(t_img *img, int color)
{
	draw_rectangle_fill(img,
		new_ipoint2d(0, 0),
		new_ipoint2d(MAP_WIDTH, MAP_HEIGHT), color);
}

int	update_loop(void *params)
{
	t_cub3d	*p;

	p = (t_cub3d *)params;
	return (render_main_loop(p));
}
