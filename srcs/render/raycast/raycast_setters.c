/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_setters.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 11:03:47 by fdeleard          #+#    #+#             */
/*   Updated: 2025/08/29 11:04:13 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	set_neg_dir_ray_lenght(double ray_start, double map_check,
			double ray_unit_step_size)
{
	return ((ray_start - map_check) * ray_unit_step_size);
}

double	set_pos_dir_ray_lenght(double ray_start, double map_check,
			double ray_unit_step_size)
{
	return ((map_check + 1.0 - ray_start) * ray_unit_step_size);
}
