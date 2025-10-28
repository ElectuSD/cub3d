/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 11:10:21 by fdeleard          #+#    #+#             */
/*   Updated: 2025/10/28 10:05:25 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_parsing.h"

bool	is_duplicate_error(t_error error)
{
	return (error == NORTH_DUPPLICATE || error == SOUTH_DUPPLICATE
		|| error == WEST_DUPPLICATE || error == EAST_DUPPLICATE
		|| error == FLOOR_DUPPLICATE || error == CEILING_DUPPLICATE);
}

bool	is_map_error(t_error error)
{
	return (error == MAP_DUPPLICATE || error == MAP_NOT_LAST
		|| error == MAP_NOT_CLOSED);
}

bool	is_missing_error(t_error error)
{
	return (error == MISSING_COLOR || error == MISSING_TEXTURE
		|| error == MISSING_MAP || error == MISSING_PLAYER);
}

bool	is_invalid_error(t_error error)
{
	return (error == INVALID_COLOR || error == INVALID_TEXTURE);
}
