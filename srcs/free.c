/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 11:14:27 by fdeleard          #+#    #+#             */
/*   Updated: 2025/08/26 11:39:32 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cub3d.h"

int	free_cub3d_and_exit(void *params)
{
	t_cub3d	*p;

	p = params;
	destroy_mlx_ptrs(&p->win_ptr, &p->raycast.img_ptr,
		&p->minimap.img_ptr, &p->mlx_ptr);
	free_map(&p->map);
	exit(0);
}

void	free_cub3d(t_cub3d	*p)
{
	destroy_mlx_ptrs(&p->win_ptr, &p->raycast.img_ptr,
		&p->minimap.img_ptr, &p->mlx_ptr);
	free_map(&p->map);
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

void	free_map(t_map *map)
{
	size_t	i;

	i = 0;
	while (map->map[i])
	{
		free(map->map[i]);
		map->map[i] = NULL;
		i++;
	}
	free(map->map);
	map->map = NULL;
	free_textures(&map->textures);
}

void	free_textures(t_textures *textures)
{
	if (textures->north)
		free(textures->north);
	if (textures->south)
		free(textures->south);
	if (textures->west)
		free(textures->west);
	if (textures->east)
		free(textures->east);
}
