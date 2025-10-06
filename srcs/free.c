/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <fdeleard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 03:12:16 by fdeleard          #+#    #+#             */
/*   Updated: 2025/10/06 10:51:37 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "mlx.h"

#include "libft_io.h"

#include "cub3d.h"

int	free_cub3d_and_exit(void *params)
{
	t_cub3d	*p;

	p = params;
	free_map(p);
	destroy_mlx_ptrs(&p->win_ptr, &p->raycast.img_ptr,
		&p->minimap.img_ptr, &p->mlx_ptr);
	exit(0);
}

void	free_cub3d(t_cub3d	*p)
{
	free_map(p);
	destroy_mlx_ptrs(&p->win_ptr, &p->raycast.img_ptr,
		&p->minimap.img_ptr, &p->mlx_ptr);
	get_next_line(NULL, 0, GNL_FLUSH);
}

void	destroy_mlx_ptrs(void **win_ptr, void **raycast_ptr,
			void **minimap_ptr, void **mlx_ptr)
{
	if (raycast_ptr && *raycast_ptr && mlx_ptr && *mlx_ptr)
	{
		mlx_destroy_image(*mlx_ptr, *raycast_ptr);
		*raycast_ptr = NULL;
	}
	if (minimap_ptr && *minimap_ptr && mlx_ptr && *mlx_ptr)
	{
		mlx_destroy_image(*mlx_ptr, *minimap_ptr);
		*minimap_ptr = NULL;
	}
	if (win_ptr && *win_ptr && *mlx_ptr)
	{
		mlx_destroy_window(*mlx_ptr, *win_ptr);
		*win_ptr = NULL;
	}
	if (mlx_ptr && *mlx_ptr)
	{
		mlx_destroy_display(*mlx_ptr);
		free(*mlx_ptr);
		*mlx_ptr = NULL;
	}
}

void	free_map(t_cub3d *p)
{
	size_t	i;

	i = 0;
	while (p->map.map && p->map.map[i])
	{
		free(p->map.map[i]);
		p->map.map[i] = NULL;
		i++;
	}
	if (p->map.map)
	{
		free(p->map.map);
		p->map.map = NULL;
	}
	free_textures(p->mlx_ptr, &p->map.textures);
}

void	free_textures(void *mlx_ptr, t_textures *textures)
{
	if (textures->north)
	{
		free(textures->north);
		if (textures->n.img_ptr)
			mlx_destroy_image(mlx_ptr, textures->n.img_ptr);
	}
	if (textures->south)
	{
		free(textures->south);
		if (textures->s.img_ptr)
			mlx_destroy_image(mlx_ptr, textures->s.img_ptr);
	}
	if (textures->west)
	{
		free(textures->west);
		if (textures->w.img_ptr)
			mlx_destroy_image(mlx_ptr, textures->w.img_ptr);
	}
	if (textures->east)
	{
		free(textures->east);
		if (textures->e.img_ptr)
			mlx_destroy_image(mlx_ptr, textures->e.img_ptr);
	}
}
