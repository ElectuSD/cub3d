/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 10:49:45 by fdeleard          #+#    #+#             */
/*   Updated: 2025/08/25 21:27:57 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>

#include <cub3d_map.h>
#include "cub3d_render.h"

static double		get_vector_lenght(t_point2d vec);
static t_point2d	get_norm_vector(t_point2d vec);
static t_point2d	scale_2dpoint(t_point2d a, int scale);

void	raycast(t_img *img, t_map *map)
{
	int			scale = img->width / map->cols;

	t_point2d	vRayStart = map->player.pos;
	t_point2d	dirVec = get_angle_vector(map->player.angle);
	t_point2d	vRayDir = dirVec;(void)get_norm_vector(new_point2d(dirVec.x * vRayStart.x, dirVec.y * vRayStart.y));
	t_point2d	vRayUnitStepSize = new_point2d(fabs(1.0f / vRayDir.x), fabs(1.0f / vRayDir.y));
	t_point2d	vMapCheck;

	printf("ANGLE : %f\n", map->player.angle);
	printf("X : %f | Y : %f\n", dirVec.x, dirVec.y);

	vMapCheck.x = (int)vRayStart.x;
	vMapCheck.y = (int)vRayStart.y;
	t_point2d	vRayLenght1D;
	t_point2d	vStep;

	if (vRayStart.x < map->cols && vRayStart.x >= 0 && vRayStart.y < map->rows && vRayStart.y >= 0 && map->map[(int)vRayStart.y][(int)vRayStart.x] == '1')
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
		printf("X : %f | Y : %f\n", vIntersection.x, vIntersection.y);
		draw_line(img, scale_2dpoint(map->player.pos, scale), vIntersection, 0xFF0000);
	}
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

static t_point2d	scale_2dpoint(t_point2d a, int scale)
{
	return (new_point2d(a.x * scale, a.y * scale));
}
