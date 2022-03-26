/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinestr <fsinestr@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 14:36:45 by fsinestr          #+#    #+#             */
/*   Updated: 2021/10/25 14:48:29 by fsinestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_nbrlen(int n)
{
	size_t	nlen;

	nlen = 1;
	while (n / 10)
	{
		nlen++;
		n /= 10;
	}
	return (nlen);
}

static int	ft_check_underflow(int base)
{
	int	int_min;

	int_min = -2147483647 - 1;
	return (base == int_min);
}

static char	*ft_itoaa(int n, int sign)
{
	char	*nstr;
	size_t	nlen;

	nlen = ft_nbrlen(n) + sign + 1;
	nstr = malloc(nlen);
	if (!nstr)
		return (nstr);
	if (n == 0)
		nstr[0] = '0';
	nstr[--nlen] = '\0';
	if (sign)
		nstr[0] = '-';
	while (n)
	{
		nstr[--nlen] = (n % 10) + '0';
		n /= 10;
	}
	return (nstr);
}

char	*ft_itoa(int n)
{
	int	sign;

	sign = 0;
	if (n < 0)
		sign = 1;
	if (sign && !ft_check_underflow(n))
		n = -n;
	else if (ft_check_underflow(n))
		return (ft_strdup("-2147483648"));
	return (ft_itoaa(n, sign));
}
