/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_parsing.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 13:29:53 by fdeleard          #+#    #+#             */
/*   Updated: 2025/09/02 12:41:01 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_PARSING_H
# define CUB3D_PARSING_H

# include "cub3d_map.h"

# define DEFAULT_TRIM " \t\n"

typedef struct s_list		t_list;

typedef enum e_error
{
	NO_ERRORS = 0,
	PARSE_ERROR,
	MALLOC_ERROR,
	CEILING_DUPPLICATE,
	FLOOR_DUPPLICATE,
	NORTH_DUPPLICATE,
	SOUTH_DUPPLICATE,
	WEST_DUPPLICATE,
	EAST_DUPPLICATE,
	MAP_DUPPLICATE,
	MAP_NOT_LAST,
	INVALID_MAP_LINE,
	MAP_NOT_CLOSED,
	INCOMPLETE_MAP,
	INVALID_COLOR,
	MISSING_COLOR,
	MISSING_MAP,
	MISSING_TEXTURE,
	MISSING_PLAYER,
}	t_error;

typedef struct s_parser
{
	char		*line;
	t_map		*map;
	t_list		*map_list;
	t_map_info	map_infos;
	bool		c_done;
	bool		f_done;
	bool		n_done;
	bool		s_done;
	bool		w_done;
	bool		e_done;
	bool		parsing_map;
	bool		parsing_map_done;
}	t_parser;

/* MAIN PARSING FUNCTION */
int			parse(t_map *map);

/* PARSE MAP */
int			parse_map(t_parser *parser);

/* CHECKS IF MAP IS CLOSED BY WALLS */
bool		map_is_closed(char **map, size_t map_size);

/* PARSE CEILING AND FLOOR RGB COLORS */
int			parse_colors(t_parser *parser);

/* PARSE TEXTURES PATHS */
int			parse_textures(t_parser *parser);

/* UTILS FUNCTIONS FOR PARSING */
int			get_next_non_empty_line(char **line, int fd);
void		free_parser_line(char **line);
char		*trim_end_of_line(char *line);
char		*skip_leading_chars(char *line);

/* CONVERT MAP LIST INTO MAP CHAR ** */
char		**convert_list(t_list *map_list);

/* LINE CHARACTER VALIDATION FUNCTION */
bool		is_valid_map_line(t_map_info *infos, char *line);

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

/* PRINTS ERROR MESSAGE BASED ON ERROR DURING PARSING */
void		print_parser_error(t_error error);

#endif
