/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinestr <fsinestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 15:54:00 by fsinestr          #+#    #+#             */
/*   Updated: 2022/01/05 15:58:11 by fsinestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_utoa(unsigned long value, char *buffer, int radix)
{
	char	*digits;

	digits = "0123456789abcdef";
	if (radix == OCTAL || radix == DECIMAL || radix == HEX)
	{
		*--buffer = '\0';
		if (value == 0)
			*--buffer = '0';
		while (value > 0)
		{
			*--buffer = digits[value % radix];
			value /= radix;
		}
		return (ft_strdup(buffer));
	}
	return ((void *) 0);
}

char	*ft_utoa_upper(unsigned long value, char *buffer, int radix)
{
	char	*tmp;
	char	*s;

	tmp = ft_utoa(value, buffer, radix);
	if (!tmp)
		return ((void *) 0);
	s = tmp;
	while (*tmp)
	{
		if (*tmp >= 97 && *tmp <= 122)
			*tmp = (*tmp - 32);
		tmp++;
	}
	return (s);
}
