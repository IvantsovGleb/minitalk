/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinestr <fsinestr@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 14:36:45 by fsinestr          #+#    #+#             */
/*   Updated: 2021/10/25 22:04:49 by fsinestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needllen;
	size_t	i;

	i = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	needllen = ft_strlen(needle);
	while (i < len && haystack[i] && len >= needllen + i)
	{
		if (0 == ft_strncmp(haystack + i, needle, needllen))
			return ((char *)(haystack + i));
		i++;
	}
	return (NULL);
}
