/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinestr <fsinestr@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 14:36:45 by fsinestr          #+#    #+#             */
/*   Updated: 2022/01/04 22:42:59 by fsinestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*copy;
	size_t	slen;

	if (!str)
		return (NULL);
	slen = ft_strlen(str) + 1;
	copy = (char *)malloc(slen);
	if (!copy)
		return (NULL);
	ft_memcpy(copy, str, slen);
	return (copy);
}
