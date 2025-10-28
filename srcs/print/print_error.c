/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 11:01:36 by fdeleard          #+#    #+#             */
/*   Updated: 2025/10/28 10:06:14 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "cub3d_parsing.h"

static void	print_map_error(t_error error);
static void	print_invalid_error(t_error error);
static void	print_missing_error(t_error error);
static void	print_dupplicate_error(t_error error);

void	print_error_helper(t_error error)
{
	if (is_duplicate_error(error))
		print_dupplicate_error(error);
	if (is_map_error(error))
		print_map_error(error);
	if (is_missing_error(error))
		print_missing_error(error);
	if (is_invalid_error(error))
		print_invalid_error(error);
}

static void	print_map_error(t_error error)
{
	if (error == MAP_DUPPLICATE)
		printf("Error\nTwo maps found in map\n");
	if (error == MAP_NOT_LAST)
		printf("Error\nMap content is not last\n");
	if (error == MAP_NOT_CLOSED)
		printf("Error\nMap not closed by walls\n");
}

static void	print_invalid_error(t_error error)
{
	if (error == INVALID_COLOR)
		printf("Error\nInvalid RGB color\n");
	if (error == INVALID_TEXTURE)
		printf("Error\nInvalid Texture Found\n");
}

static void	print_missing_error(t_error error)
{
	if (error == MISSING_COLOR)
		printf("Error\nMissing color in map\n");
	if (error == MISSING_TEXTURE)
		printf("Error\nMissing texture in map\n");
	if (error == MISSING_MAP)
		printf("Error\nMissing map in map\n");
	if (error == MISSING_PLAYER)
		printf("Error\nMissing player in map\n");
}

static void	print_dupplicate_error(t_error error)
{
	if (error == NORTH_DUPPLICATE)
		printf("Error\nNorth texture dupplicate in map\n");
	if (error == SOUTH_DUPPLICATE)
		printf("Error\nSouth texture dupplicate in map\n");
	if (error == WEST_DUPPLICATE)
		printf("Error\nWest texture dupplicate in map\n");
	if (error == EAST_DUPPLICATE)
		printf("Error\nEast texture dupplicate in map\n");
	if (error == CEILING_DUPPLICATE)
		printf("Error\nCeiling colors dupplicate in map\n");
	if (error == FLOOR_DUPPLICATE)
		printf("Error\nFloor colors dupplicate in map\n");
}
