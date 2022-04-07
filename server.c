/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinestr <fsinestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:58:56 by fsinestr          #+#    #+#             */
/*   Updated: 2022/04/07 17:58:58 by fsinestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "libft/libft.h"
#include "ft_printf.h"

int	g_counter = 1;

void	disposition(int sig, siginfo_t *info, void *ucontext)
{
	static pid_t			pid;
	static unsigned char	ch;

	(void)ucontext;
	if (sig == SIGUSR2)
	{
		ch |= g_counter;
		g_counter = g_counter << 1;
	}
	else
	{
		g_counter = g_counter << 1;
	}
	if (g_counter == 256)
	{
		write(1, &ch, 1);
		ch = 0U;
		g_counter = 1;
	}
	if (info->si_pid != 0)
		pid = info->si_pid;
	kill(pid, SIGUSR2);
}

int	main(void)
{
	struct sigaction	action;

	ft_memset(&action, 0, sizeof(action));
	action.sa_sigaction = disposition;
	action.sa_flags = SA_SIGINFO;
	sigemptyset(&action.sa_mask);
	sigaddset(&action.sa_mask, SIGUSR1);
	sigaddset(&action.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &action, (void *) 0);
	sigaction(SIGUSR2, &action, (void *) 0);
	ft_printf("PID %d\n", getpid());
	while (1)
		pause();
	return (0);
}
