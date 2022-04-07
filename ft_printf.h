/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinestr <fsinestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 15:54:07 by fsinestr          #+#    #+#             */
/*   Updated: 2022/01/05 15:58:11 by fsinestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

size_t	ft_putchar(int c);
size_t	ft_putstr(char *s);
char	*ft_address(void *address, char *buffer);

int		ft_printf(const char *format, ...);

#endif
