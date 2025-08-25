/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 10:49:45 by fdeleard          #+#    #+#             */
/*   Updated: 2025/08/25 15:31:14 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>

#include <cub3d_map.h>
#include "cub3d_render.h"

static double		get_vector_lenght(t_point2d vec);
static t_point2d	get_dir_vector(t_directions dir);
static t_point2d	get_norm_vector(t_point2d vec);

void	raycast(t_img *img, t_map *map)
{
	int			scale = img->width / map->cols;

	t_point2d	vRayStart = new_point2d(map->player.x, map->player.y);
	t_point2d	dirVec = get_dir_vector(map->player.player_direction);

	//printf("X : %f | Y : %f\n", dirVec.x, dirVec.y);
	//printf("X : %f | Y : %f\n", vRayStart.x, vRayStart.y);

	t_point2d	vRayDir = get_norm_vector(new_point2d(dirVec.x * vRayStart.x, dirVec.y * vRayStart.y));

	printf("X : %f | Y : %f\n", vRayDir.x, vRayDir.y);

	t_point2d	vRayUnitStepSize = new_point2d(fabs(1.0f / vRayDir.x), fabs(1.0f / vRayDir.y));
	t_point2d	vMapCheck = vRayStart;
	t_point2d	vRayLenght1D;
	t_point2d	vStep;

	if (map->map[(int)vRayStart.y][(int)vRayStart.x] == '1')
		return ;
	if (vRayDir.x < 0)
	{
		vStep.x = -1;
		vRayLenght1D.x = (vRayStart.x - (double)vMapCheck.x) * vRayUnitStepSize.x;
	}
	else
	{
		vStep.x = 1;
		vRayLenght1D.x = ((double)(vMapCheck.x + 1) - vRayStart.x) * vRayUnitStepSize.x;
	}
	if (vRayDir.y < 0)
	{
		vStep.y = -1;
		vRayLenght1D.y = (vRayStart.y - (double)vMapCheck.y) * vRayUnitStepSize.y;
	}
	else
	{
		vStep.y = 1;
		vRayLenght1D.y = ((double)(vMapCheck.y + 1) - vRayStart.y) * vRayUnitStepSize.y;
	}

	bool	hit = false;
	double	maxDistance = 100;
	double	distance = 0;
	while (!hit && distance < maxDistance)
	{
		if (vRayLenght1D.x < vRayLenght1D.y)
		{
			vMapCheck.x += vStep.x;
			distance = vRayLenght1D.x;
			vRayLenght1D.x += vRayUnitStepSize.x;
		}
		else
		{
			vMapCheck.y += vStep.y;
			distance = vRayLenght1D.y;
			vRayLenght1D.y += vRayUnitStepSize.y;
		}

		if (vMapCheck.x >= 0 && vMapCheck.x < (int)map->cols && vMapCheck.y >= 0 && vMapCheck.y < (int)map->rows)
			if (map->map[(int)(vMapCheck.y)][(int)(vMapCheck.x)] == '1')
				hit = true;
	}
	if (hit)
	{
		t_point2d	vIntersection;

		vIntersection.x = (vRayStart.x + (vRayDir.x * distance)) * scale;
		vIntersection.y = (vRayStart.y + (vRayDir.y * distance)) * scale;
		draw_line(img, new_point2d(map->player.x * scale, map->player.y * scale), vIntersection, 0xFF0000);
	}
}

static t_point2d	get_dir_vector(t_directions dir)
{
	if (dir == NORTH)
		return (new_point2d(0, -1));
	if (dir == SOUTH)
		return (new_point2d(0, 1));
	if (dir == WEST)
		return (new_point2d(-1, 0));
	if (dir == EAST)
		return (new_point2d(1, 0));
	return (new_point2d(0, 1));
}

static t_point2d	get_norm_vector(t_point2d vec)
{
	double	l;

	l = get_vector_lenght(vec);
	return (new_point2d(vec.x / l, vec.y / l));
}

static double	get_vector_lenght(t_point2d vec)
{
	return (sqrt((vec.x * vec.x) + (vec.y * vec.y)));
}
