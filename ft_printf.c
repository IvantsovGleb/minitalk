/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinestr <fsinestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:58:49 by fsinestr          #+#    #+#             */
/*   Updated: 2022/04/07 17:58:53 by fsinestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_conversion(int c, va_list *args)
{
	char	buffer[sizeof(int) * 5 + 1];

	if (c == 's')
		return (ft_strdup(va_arg(*args, char *)));
	if (c == 'p')
		return (ft_address(va_arg(*args, void *),
				&buffer[sizeof(int) * 5 + 1]));
	if (c == 'd' || c == 'i')
		return (ft_itoa(va_arg(*args, int)));
	if (c == 'u')
		return (ft_utoa(
				va_arg(*args, unsigned int),
				&buffer[sizeof(int) * 5 + 1],
				DECIMAL));
	if (c == 'x')
		return (ft_utoa(
				va_arg(*args, unsigned int),
				&buffer[sizeof(int) * 5 + 1],
				HEX));
	if (c == 'X')
		return (ft_utoa_upper(
				va_arg(*args, unsigned int),
				&buffer[sizeof(int) * 5 + 1],
				HEX));
	return ((void *) 0);
}

int	ft_printf(const char *format, ...)
{
	size_t	count;
	char	*s;
	va_list	args;

	va_start(args, format);
	count = 0;
	while (*format)
	{
		if (*format == '%' && ft_strchr("spdiuxX", *(format + 1)))
		{
			s = ft_conversion(*++format, &args);
			count += ft_putstr(s);
			free(s);
		}
		else if (*format == '%' && (*++format == 'c'))
			count += ft_putchar(va_arg(args, int));
		else
			count += ft_putchar(*format);
		format++;
	}
	va_end(args);
	return (count);
}
