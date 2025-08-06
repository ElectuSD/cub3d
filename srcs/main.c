/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 10:29:19 by fdeleard          #+#    #+#             */
/*   Updated: 2025/08/06 11:38:24 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "cub3d_map.h"
#include "cub3d_utils.h"

int	main(int argc, char **argv)
{
	t_map	map;
	int		map_fd;

	if (argc != 2)
	{
		printf("Usage : ./cub3d <map_name>.cub\n");
		return (1);
	}
	map_fd = open_file(argv[1]);
	if (map_fd == -1)
		return (1);
	return (0);
}
