/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinestr <fsinestr@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 14:36:45 by fsinestr          #+#    #+#             */
/*   Updated: 2021/10/25 14:48:30 by fsinestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*sdup;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	sdup = ft_strdup(s);
	if (!f || !sdup)
		return (NULL);
	while (sdup[i])
	{
		sdup[i] = f(i, sdup[i]);
		i++;
	}
	return (sdup);
}
