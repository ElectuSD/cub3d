/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 12:35:56 by fdeleard          #+#    #+#             */
/*   Updated: 2025/08/27 12:36:25 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_colors.h"

int	color_to_int(t_rgb color)
{
	return ((0xFF << 24) | (color.r << 16) | (color.g << 8) | color.b);
}

t_rgb	int_to_color(int color)
{
	t_rgb	new_color;

	new_color.r = (color >> 16) & 0xFF;
	new_color.g = (color >> 8) & 0xFF;
	new_color.b = color & 0xFF;
	return (new_color);
}
