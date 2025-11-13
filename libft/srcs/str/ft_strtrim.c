/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:25:07 by fdeleard          #+#    #+#             */
/*   Updated: 2025/05/28 18:58:23 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_str.h>

static int	char_is_set(char c, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	s1_len;

	s1_len = ft_strlen(s1);
	if (s1_len == 0)
		return (ft_strdup(""));
	i = 0;
	while (s1[i] && char_is_set(s1[i], set))
		i++;
	j = s1_len;
	while (j > i && char_is_set(s1[j - 1], set))
		j--;
	if (i == j)
		return (ft_strdup(""));
	str = ft_substr(s1, i, j - i);
	return (str);
}

static int	char_is_set(char c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}
