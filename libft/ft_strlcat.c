/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinestr <fsinestr@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 14:36:45 by fsinestr          #+#    #+#             */
/*   Updated: 2021/10/25 17:33:59 by fsinestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t		dstlen;
	char		*d;
	const char	*s;

	dstlen = 0;
	d = dst;
	s = src;
	while (*d && dstsize > 0)
	{
		dstlen++;
		d++;
		dstsize--;
	}
	while (dstsize > 1 && *s)
	{
		*d++ = *s++;
		dstsize--;
	}
	if (dstsize == 1 || *s == 0)
		*d = '\0';
	while (*s)
		s++;
	return (s - src + dstlen);
}
