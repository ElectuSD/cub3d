/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 10:49:45 by fdeleard          #+#    #+#             */
/*   Updated: 2025/08/27 12:41:50 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>

#include <cub3d_map.h>
#include "cub3d_render.h"

void	raycast(t_img *img, t_map *map)
{
	int			w, h;
	int			x;
	int			scale;

	x = 0;
	w = 1920;
	h = 1080;
	scale = img->width / map->cols;
	draw_rectangle_fill(img, new_point2d(0, 0), new_point2d(img->width, (int)(img->height/ 2)), color_to_int(map->ceiling));
	draw_rectangle_fill(img, new_point2d(0, (int)(img->height / 2)), new_point2d(img->width, img->height), color_to_int(map->floor));

	while (x < w)
	{

		double		cameraX = 2 * x / (double)w - 1;

		printf("CAMERAX : %f\n", cameraX * scale);
	//	draw_line(img, new_point2d((map->player.pos.x + map->player.dir.x - map->player.plane.x) * scale, \
	//								(map->player.pos.y + map->player.dir.y - map->player.plane.y) * scale), \
	//					new_point2d((map->player.pos.x + map->player.dir.x + map->player.plane.x) * scale, \
	//								(map->player.pos.y + map->player.dir.y + map->player.plane.y) * scale), 0x00FFFF);
		t_point2d	vRayStart = map->player.pos;

		t_point2d	vRayDir = map->player.dir;
		vRayDir.x += (map->player.plane.x * cameraX);
		vRayDir.y += (map->player.plane.y * cameraX);

		//printf("X : %f | Y : %f\n", vRayDir.x, vRayDir.y);
		t_point2d	vRayUnitStepSize;
		vRayUnitStepSize.x = (vRayDir.x == 0) ? 1e30 : fabs(1 / vRayDir.x);
		vRayUnitStepSize.y = (vRayDir.y == 0) ? 1e30 : fabs(1 / vRayDir.y);

		t_point2d	vMapCheck;
		vMapCheck.x = (int)vRayStart.x;
		vMapCheck.y = (int)vRayStart.y;

		t_point2d	vStep;
		t_point2d	vRayLenght1D;
		if (vRayStart.x < map->cols && vRayStart.x >= 0 && vRayStart.y < map->rows && vRayStart.y >= 0 && map->map[(int)vRayStart.y][(int)vRayStart.x] == '1')
			return ;
		if (vRayDir.x < 0)
		{
			vStep.x = -1;
			vRayLenght1D.x = (vRayStart.x - vMapCheck.x) * vRayUnitStepSize.x;
		}
		else
		{
			vStep.x = 1;
			vRayLenght1D.x = (vMapCheck.x + 1.0 - vRayStart.x) * vRayUnitStepSize.x;
		}
		if (vRayDir.y < 0)
		{
			vStep.y = -1;
			vRayLenght1D.y = (vRayStart.y - vMapCheck.y) * vRayUnitStepSize.y;
		}
		else
		{
			vStep.y = 1;
			vRayLenght1D.y = (vMapCheck.y + 1.0 - vRayStart.y) * vRayUnitStepSize.y;
		}

		int		side;
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
				side = 0;
			}
			else
			{
				vMapCheck.y += vStep.y;
				distance = vRayLenght1D.y;
				vRayLenght1D.y += vRayUnitStepSize.y;
				side = 1;
			}
			if (vMapCheck.x >= 0 && vMapCheck.x < (int)map->cols && vMapCheck.y >= 0 && vMapCheck.y < (int)map->rows)
				if (map->map[(int)(vMapCheck.y)][(int)(vMapCheck.x)] == '1')
					hit = true;
		}
		double	perpWallDist;
		if (side == 0)
			perpWallDist = vRayLenght1D.x - vRayUnitStepSize.x;
		else
			perpWallDist = vRayLenght1D.y - vRayUnitStepSize.y;

		int		lineHeight = (int)(h / perpWallDist);
		int		drawStart = -lineHeight / 2 + h / 2;
		if (drawStart < 0)
			drawStart = 0;
		int drawEnd = lineHeight / 2 + h / 2;
		if (drawEnd >= h)
			drawEnd = h - 1;

		int color;
		color = 0xFF0000;
		if (side == 1)
			color = 0xAA0000;
		(void)color;
		(void)img;
		draw_line(img, new_point2d(x, drawStart), new_point2d(x, drawEnd), color);
		x++;
	}
}
