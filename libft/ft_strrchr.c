/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinestr <fsinestr@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 14:36:45 by fsinestr          #+#    #+#             */
/*   Updated: 2021/10/25 20:16:44 by fsinestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t		i;
	const char	*pos;

	i = 0;
	pos = NULL;
	while (s[i])
	{
		if (s[i] == (char)c)
			pos = &s[i];
		i++;
	}
	if ((char)c == '\0')
		return ((char *)s + ft_strlen(s));
	return ((char *)pos);
}
