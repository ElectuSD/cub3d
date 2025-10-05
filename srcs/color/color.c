/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <fdeleard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 02:07:22 by fdeleard          #+#    #+#             */
/*   Updated: 2025/10/05 02:07:33 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_colors.h"

t_rgb	create_color(unsigned char r, unsigned char g, unsigned char b)
{
	t_rgb	new_color;

	new_color.r = r;
	new_color.g = g;
	new_color.b = b;
	return (new_color);
}
