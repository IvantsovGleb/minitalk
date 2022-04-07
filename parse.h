/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinestr <fsinestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 19:32:10 by fsinestr          #+#    #+#             */
/*   Updated: 2022/04/07 19:32:27 by fsinestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include <limits.h>

typedef struct s_number
{
	unsigned long	nbr;
	int				sign;
}					t_number;

int	parse_int(const char *s, int *i);

#endif
