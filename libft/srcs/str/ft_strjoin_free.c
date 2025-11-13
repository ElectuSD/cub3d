/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:40:54 by fdeleard          #+#    #+#             */
/*   Updated: 2025/06/16 11:45:35 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_str.h>

/**
 * @brief Concatenates two strings and frees one or both based on a flag.
 *
 * This function returns a new string formed by concatenating @p s1 and @p s2.
 * It allows conditional freeing of the input strings based on the value of
 * @p flag.
 *
 * Memory for the resulting string is dynamically allocated. If allocation
 * fails, NULL is returned and no freeing occurs.
 *
 * @param s1 First string to concatenate (may be freed depending on @p flag).
 * @param s2 Second string to concatenate (may be freed depending on @p flag).
 * @param flag Indicates which strings to free after concatenation.
 *             - FREE_S1: frees s1 only
 *             - FREE_S2: frees s2 only
 *             - FREE_BOTH: frees both s1 and s2
 * @return A new null-terminated string or NULL on allocation failure.
 */

static void	check_input(char *s1, char *s2, char **str);
static void	free_strjoin(char *s1, char *s2, t_strjoin_free flag);

char	*ft_strjoin_free(char *s1, char *s2, t_strjoin_free flag)
{
	char	*str;
	size_t	i;
	size_t	j;

	check_input(s1, s2, &str);
	if (!str)
	{
		free_strjoin(s1, s2, flag);
		return (NULL);
	}
	i = 0;
	j = 0;
	while (s1 && s1[i])
		str[j++] = s1[i++];
	i = 0;
	while (s2 && s2[i])
		str[j++] = s2[i++];
	str[j] = '\0';
	free_strjoin(s1, s2, flag);
	return (str);
}

static void	free_strjoin(char *s1, char *s2, t_strjoin_free flag)
{
	if (flag == FREE_S1 || flag == FREE_BOTH)
		free(s1);
	if (flag == FREE_S2 || flag == FREE_BOTH)
		free(s2);
}

static void	check_input(char *s1, char *s2, char **str)
{
	int	size;

	if (!s1 && s2)
	{
		size = ft_strlen(s2);
		*str = malloc((size + 1) * sizeof(char));
	}
	else if (s1 && !s2)
	{
		size = ft_strlen(s1);
		*str = malloc((size + 1) * sizeof(char));
	}
	else if (s1 && s2)
	{
		size = ft_strlen(s1) + ft_strlen(s2);
		*str = malloc((size + 1) * sizeof(char));
	}
	else
		*str = malloc(1 * sizeof(char));
}
