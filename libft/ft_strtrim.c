/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinestr <fsinestr@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 14:36:45 by fsinestr          #+#    #+#             */
/*   Updated: 2021/10/25 19:20:36 by fsinestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strcmp(const char *s1, const char *s2)
{
	const char	*s11;
	const char	*s22;

	s11 = s1;
	s22 = s2;
	while (*s11 && (*s11 == *s22))
	{
		s11++;
		s22++;
	}
	return (*(unsigned char *)s11 - *(unsigned char *)s22);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	size_t	start;
	char	*ts;

	if (!s1)
		return (NULL);
	if (!ft_strcmp(s1, ""))
		return (ft_calloc(1, 1));
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	len = ft_strlen(s1) - 1;
	while (len && ft_strchr(set, s1[len]))
		len--;
	if (!ft_strncmp(s1, &s1[start], ft_strlen(s1)) && s1[len + 1] == '\0')
		return (ft_substr(s1, start, ft_strlen(s1)));
	if (len == 0)
		return (ft_calloc(1, 1));
	ts = malloc(len - start + 2);
	if (!ts)
		return (NULL);
	ft_strlcpy(ts, &s1[start], len - start + 2);
	return (ts);
}
