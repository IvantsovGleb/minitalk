/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinestr <fsinestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 19:30:43 by fsinestr          #+#    #+#             */
/*   Updated: 2022/04/07 19:32:35 by fsinestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static int	is_digit(int c)
{
	return (c >= '0' && c <= '9');
}

static int	uo_flow(unsigned long *nbr, int sign, int c)
{
	unsigned long	cutoff;
	int				cutlim;

	cutoff = (unsigned long)LONG_MAX / 10;
	if (sign)
		cutlim = (unsigned long)LONG_MIN % 10;
	else
		cutlim = (unsigned long)LONG_MAX % 10;
	if (*nbr > cutoff || (*nbr == cutoff && c > cutlim))
	{
		if (sign)
			*nbr = LONG_MIN;
		else
			*nbr = LONG_MAX;
		return (1);
	}
	return (0);
}

static void	to_int(const char **p_s, const char **end_p,
		t_number *num, int *errn)
{
	int	c;

	num->nbr = 0;
	while (**p_s && is_digit((unsigned char)**p_s))
	{
		c = **p_s - '0';
		*errn = uo_flow(&num->nbr, num->sign, c);
		if (!*errn)
			num->nbr = num->nbr * 10 + c;
		else
			break ;
		*end_p = ++*p_s;
	}
}

static long	my_atol(const char *nptr, char **endptr, int *err)
{
	t_number	num;
	const char	*p_s;
	const char	*end_p;

	p_s = nptr;
	end_p = nptr;
	num.sign = 0;
	if (*p_s == '-')
	{
		num.sign = 1;
		p_s++;
	}
	to_int(&p_s, &end_p, &num, err);
	if (!*err && num.sign)
		num.nbr = -num.nbr;
	if (endptr)
		*endptr = (char *)end_p;
	return ((long)num.nbr);
}

int	parse_int(const char *s, int *i)
{
	int		err;
	char	*end_p;
	long	l;

	err = 0;
	l = my_atol(s, &end_p, &err);
	if (s == end_p || *end_p != '\0'
		|| ((l == LONG_MIN || l == LONG_MAX) && err)
		|| (l < INT_MIN || l > INT_MAX))
		return (0);
	else
		*i = (int) l;
	return (1);
}
