/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_str.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 15:10:26 by fdeleard          #+#    #+#             */
/*   Updated: 2025/11/13 14:11:22 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_STR_H
# define LIBFT_STR_H 

# include <stdlib.h>

typedef enum e_strjoin_free
{
	FREE_NONE,
	FREE_S1,
	FREE_S2,
	FREE_BOTH,
}	t_strjoin_free;

typedef enum e_strtok_flag
{
	SKIP_EMPTY,
	KEEP_EMPTY
}	t_strtok_flag;

int		ft_atoi(const char *nptr);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_itoa(int n);
char	*ft_strdup(const char *s1);
char	*ft_strndup(const char *str, size_t size);
char	*ft_strchr(const char *s, int c);
char	*ft_strnchr(const char *s, int c, size_t n);
char	*ft_strrchr(const char *s, int c);
char	*ft_strtok(char *str, const char *delim, t_strtok_flag flag);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strjoin_free(char *s1, char *s2, t_strjoin_free flag);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strmapi(const char *s, char (*f)(unsigned int, char));
char	*ft_strnstr(const char *big, const char *little, size_t n);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);

#endif
