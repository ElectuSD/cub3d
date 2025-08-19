/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 11:08:39 by fdeleard          #+#    #+#             */
/*   Updated: 2025/08/19 11:04:50 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_UTILS_H
# define CUB3D_UTILS_H

# include <stdbool.h>

/* OPEN MAP FILE, RETURNS FD TO MAP */
int		open_file(char *filename);

/* CHECKS .cub FILE EXTENSION */
bool	is_valid_filename(char *filename);

#endif
