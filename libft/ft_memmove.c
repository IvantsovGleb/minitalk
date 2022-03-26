/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinestr <fsinestr@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 14:36:45 by fsinestr          #+#    #+#             */
/*   Updated: 2021/10/25 14:48:29 by fsinestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!s1 && !s2)
		return (NULL);
	if (s2 < s1)
	{
		while (n--)
			*((unsigned char *)s1 + n) = *((unsigned char *)s2 + n);
	}
	else
	{
		while (i < n)
		{
			*((char *)s1 + i) = *((char *)s2 + i);
			i++;
		}
	}
	return (s1);
}
