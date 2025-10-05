/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <fdeleard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 02:42:06 by fdeleard          #+#    #+#             */
/*   Updated: 2025/10/05 03:58:50 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/time.h>

#include "mlx.h"
#include "libft_mem.h"

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_cub3d	p;

	ft_memset(&p, 0, sizeof(t_cub3d));
	if (argc != 2)
	{
		printf("Usage : ./cub3d <map_name>.cub\n");
		return (1);
	}
	// if (!is_valid_filename(argv[1]))
	// {
	// 	printf("Wrong filename, need map with .cub\n");
	// 	return (1);
	// }
	if (!init_cub3d(&p, argv[1]))
	{
		free_cub3d(&p);
		return (1);
	}
	gettimeofday(&p.frametime, NULL);
	mlx_loop(p.mlx_ptr);
	return (0);
}
