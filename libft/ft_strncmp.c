/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinestr <fsinestr@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 14:36:45 by fsinestr          #+#    #+#             */
/*   Updated: 2021/10/25 14:48:30 by fsinestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const char	*s11;
	const char	*s22;

	s11 = s1;
	s22 = s2;
	while (*s11 && n > 0 && (*s11 == *s22))
	{
		s11++;
		s22++;
		n--;
	}
	if (n == 0)
		return (0);
	return (*(unsigned char *)s11 - *(unsigned char *)s22);
}
