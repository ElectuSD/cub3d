/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 14:03:45 by fdeleard          #+#    #+#             */
/*   Updated: 2025/11/13 14:11:49 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_str.h>

static int	is_delim(const char *delim, char c);
static char	*skip_empty(char **save, const char *delim);
static char	*keep_empty(char **save, const char *delim);

char	*ft_strtok(char *str, const char *delim, t_strtok_flag flag)
{
	static char	*save = NULL;
	
	if (str)
		save = str;
	else if (!save)
		return (NULL);
	if (!delim)
		return (save);
	if (flag == SKIP_EMPTY)
		return (skip_empty(&save, delim));
	else if (flag == KEEP_EMPTY)
		return (keep_empty(&save, delim));
	else
		return (NULL);
}

static char	*keep_empty(char **save, const char *delim)
{
	char	*token_start;
	
	if (**save == '\0')
		return (NULL);
	token_start = *save;
	while (**save && !is_delim(delim, **save))
		++(*save);
	if (token_start == *save)
	{
		if (**save)
		{
			++(*save);
			return (NULL);
		}
		return (NULL);
	}
	if (**save)
	{
		**save = '\0';
		++(*save);
	}
	else
		*save = NULL;
	return (token_start);
}

static char	*skip_empty(char **save, const char *delim)
{
	char	*token_start;
	
	while (**save && is_delim(delim, **save))
		++(*save);
	if (**save == '\0')
		return (NULL);
	token_start = *save;
	while (**save && !is_delim(delim, **save))
		++(*save);
	if (**save)
	{
		**save = '\0';
		++(*save);
	}
	else
		*save = NULL;
	return (token_start);
}

static int	is_delim(const char *delim, char c)
{
	while (*delim)
	{
		if (*delim == c)
			return (1);
		delim++;
	}
	return (0);
}
