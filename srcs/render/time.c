/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <fdeleard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 04:00:29 by fdeleard          #+#    #+#             */
/*   Updated: 2025/10/05 04:00:51 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>

#include "cub3d.h"

double	get_delta_time(t_cub3d *p)
{
	double			delta;
	struct timeval	cur_time;

	gettimeofday(&cur_time, NULL);
	delta = (cur_time.tv_sec - p->frametime.tv_sec) + (cur_time.tv_usec
			- p->frametime.tv_usec) / 1000000.0;
	p->frametime = cur_time;
	return (delta);
}
