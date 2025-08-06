/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 11:40:22 by fdeleard          #+#    #+#             */
/*   Updated: 2025/08/06 14:28:31 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "libft_str.h"
#include "cub3d_parsing.h"

bool	is_color(char *line)
{
	if (!line)
		return (false);
	return (is_floor(line) || is_ceiling(line));
}

bool	is_floor(char *line)
{
	return (ft_strncmp(line, "F", 1) == 0);
}

bool	is_ceiling(char *line)
{
	return (ft_strncmp(line, "C", 1) == 0);
}
