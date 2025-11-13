/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:57:52 by fdeleard          #+#    #+#             */
/*   Updated: 2025/05/28 18:57:54 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_str.h>
#include <libft_mem.h>

static void		*free_strs(char **strs, int count);
static char		**fill_tab(char **strs, char const *s, char c);
static size_t	count_words(char const *s, char c);

/**
 * @brief Splits a string into an array of substrings based on a delimiter.
 *
 * This function splits the string 's' into substrings using the character 'c' 
 * as a delimiter.
 * It allocates memory for the resulting array of strings and returns it.
 * If memory allocation fails or the input string is NULL, it returns NULL.
 *
 * @param s The string to split.
 * @param c The delimiter character.
 * @return A pointer to the array of substrings, or NULL if memory allocation 
 *		   fails or input is invalid.
 */
char	**ft_split(char const *s, char c)
{
	char	**strs;
	size_t	word_count;

	if (!s)
		return (NULL);
	word_count = count_words(s, c);
	strs = ft_calloc(word_count + 1, sizeof(char *));
	if (!strs)
		return (NULL);
	strs = fill_tab(strs, s, c);
	return (strs);
}

static void	*free_strs(char **strs, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (NULL);
}

static char	**fill_tab(char **strs, char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		j = 0;
		while (s[i + j] != c && s[i + j])
			j++;
		if (j > 0)
		{
			strs[count] = ft_substr(s, i, j);
			if (!strs[count])
				return (free_strs(strs, count));
			i = i + j;
			count++;
		}
		else
			i++;
	}
	return (strs);
}

static size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && ((s[i + 1] == c) || (s[i + 1] == '\0')))
			count++;
		i++;
	}
	return (count);
}
