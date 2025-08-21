/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 11:14:27 by fdeleard          #+#    #+#             */
/*   Updated: 2025/08/21 13:54:38 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cub3d.h"

void	free_cub3d(t_cub3d *p)
{
	destroy_mlx_ptrs(&p->win_ptr, &p->img.img_ptr, &p->mlx_ptr);
	free_map(&p->map);
}

void	destroy_mlx_ptrs(void **win_ptr, void **img_ptr, void **mlx_ptr)
{
	if (img_ptr && *img_ptr && mlx_ptr && *mlx_ptr)
	{
		mlx_destroy_image(*mlx_ptr, *img_ptr);
		*img_ptr = NULL;
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
