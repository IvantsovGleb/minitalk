/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinestr <fsinestr@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 14:36:45 by fsinestr          #+#    #+#             */
/*   Updated: 2021/10/25 14:48:29 by fsinestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *b1, const void *b2, size_t len)
{
	const unsigned char	*p1;
	const unsigned char	*p2;

	p1 = (const unsigned char *)b1;
	p2 = (const unsigned char *)b2;
	if (len != 0)
	{
		while (len-- != 0)
		{
			if (*p1++ != *p2++)
				return (*--p1 - *--p2);
		}
	}
	return (0);
}
