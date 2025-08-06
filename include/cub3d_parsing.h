/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_parsing.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 13:29:53 by fdeleard          #+#    #+#             */
/*   Updated: 2025/08/06 11:50:07 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_PARSING_H
# define CUB3D_PARSING_H

# include <stdbool.h>

typedef struct s_list	t_list;

/* PUTS MAP INTO LIST OF NON EMPTY STRINGS */
t_list		*map_parsing(int fd);

/* GET NEXT NON EMPTY LINE IN MAP */
int			get_next_non_empty_line(char **line, int fd);

/* LINE CHARACTER VALIDATION FUNCTION */
bool		is_valid_map_line(char *line);

/* CHECKS IF LINE IS TEXTURE */
bool		is_texture(char *line);
bool		is_west(char *line);
bool		is_east(char *line);
bool		is_north(char *line);
bool		is_south(char *line);

/* CHECKS IF LINE IS COLORS */
bool		is_color(char *line);
bool		is_floor(char *line);
bool		is_ceiling(char *line);

#endif
