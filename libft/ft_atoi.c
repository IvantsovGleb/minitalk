/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinestr <fsinestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 14:36:45 by fsinestr          #+#    #+#             */
/*   Updated: 2022/01/05 15:58:11 by fsinestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	const char	*p;
	long		sign;
	long		base;

	p = nptr;
	sign = 1;
	base = 0;
	while (ft_isspace((unsigned char)*p))
		p++;
	if (*p == '+' || *p == '-')
		sign = 1 - 2 * (*p++ == '-');
	while (ft_isdigit((unsigned char)*p))
	{
		if (base < 0)
		{
			if (sign == 1)
				return (-1);
			if (sign == -1)
				return (0);
		}
		base = base * 10 + (*p++ - '0');
	}
	return ((int)(sign * base));
}
