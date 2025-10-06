/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <fdeleard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 04:02:12 by fdeleard          #+#    #+#             */
/*   Updated: 2025/10/06 10:51:00 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_mem.h"

#include "cub3d_draw.h"

void	clear_img(t_img *img, int c)
{
	ft_memset(img->addr, c, img->width * img->height * img->bytes_per_pixel);
}
