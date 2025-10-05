/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_maths.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <fdeleard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 02:00:04 by fdeleard          #+#    #+#             */
/*   Updated: 2025/10/05 02:50:31 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_MATHS_H
# define CUB3D_MATHS_H

typedef struct s_dpoint2d
{
	double	x;
	double	y;
}	t_dpoint2d;

typedef struct s_ipoint2d
{
	int		x;
	int		y;
}	t_ipoint2d;

typedef struct s_rec
{
	t_ipoint2d	tl;
	t_ipoint2d	br;
}	t_rec;

/* CREATE MATHS FUNCTIONS */
t_ipoint2d	new_ipoint2d(int x, int y);
t_dpoint2d	new_dpoint2d(double x, double y);
t_rec		new_rectangle(t_ipoint2d top_left, t_ipoint2d bottom_right);

/* CONVERTION FUNCTION */
t_ipoint2d	convert_dpoint2d_to_ipoint2d(t_dpoint2d dpoint2d);

#endif // !CUB3D_MATHS_H
