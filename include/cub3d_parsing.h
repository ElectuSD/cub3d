/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_parsing.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 13:29:53 by fdeleard          #+#    #+#             */
/*   Updated: 2025/08/06 14:11:57 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_PARSING_H
# define CUB3D_PARSING_H

# include <stdbool.h>

# define DEFAULT_TRIM " \t\n"

typedef struct s_list	t_list;
typedef struct s_map	t_map;

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
}	t_error;

typedef struct s_parser
{
	t_map	*map;
	bool	ceiling;
	bool	floor;
	bool	north;
	bool	south;
	bool	west;
	bool	east;
	bool	parsing_map;
}	t_parser;

/* MAIN PARSING FUNCTION */
int			parse(t_map *map);

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
