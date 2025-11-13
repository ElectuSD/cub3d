/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 15:21:39 by fdeleard          #+#    #+#             */
/*   Updated: 2025/09/02 20:54:01 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_UTILS_H
# define LIBFT_UTILS_H

# include <stdbool.h>

/* Free Functions */
void	ft_free_tab(void **tab);

/* Checks if char c is in set */
bool	char_in_set(char c, char *set);

/* Swaps two ints */
void	ft_swap_int(int *a, int *b);

#endif
