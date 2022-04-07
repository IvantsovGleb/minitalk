/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinestr <fsinestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:59:01 by fsinestr          #+#    #+#             */
/*   Updated: 2022/04/07 19:27:43 by fsinestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft/libft.h"
#include "ft_printf.h"
#include "parse.h"

int	g_notification;

void	notify(int sig)
{
	(void)sig;
	g_notification = 1;
}

void	send_string(pid_t pid, char *s)
{
	int	i;
	int	k;

	i = 0;
	while (s[i])
	{
		k = 0;
		while (k < (int)(sizeof(int) * 2))
		{
			g_notification = 0;
			if ((unsigned char)s[i] & (1U << k))
			{
				kill(pid, SIGUSR2);
			}
			else
			{
				kill(pid, SIGUSR1);
			}
			while (!g_notification)
				;
			k++;
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	pid_t				pid;
	struct sigaction	action;

	ft_memset(&action, 0, sizeof(action));
	action.sa_handler = notify;
	sigemptyset(&action.sa_mask);
	sigaddset(&action.sa_mask, SIGUSR2);
	sigaction(SIGUSR2, &action, (void *) 0);
	if (argc == 3 && parse_int(argv[1], &pid))
	{
		if (pid <= 0 || kill(pid, 0) == -1)
		{
			ft_printf("Error, unable to connect to server: ");
			ft_printf("ID does not exist or access denied\n");
		}
		else
			send_string(pid, argv[2]);
	}
	else
		ft_printf("Error, invalid command line arguments\n");
	return (0);
}
