#include <unistd.h>
#include <signal.h>
#include "libft/libft.h"
#include "ft_printf.h"

unsigned char    g_counter = 1;

void    disp(int sig, siginfo_t *info, void *ucontext)
{
    static pid_t prev_pid;
    static unsigned char    ch;

    (void)ucontext;

    if (g_counter == 128)
    {
        write(1, &ch,1);
        ch = 0U;
        g_counter = 1U;
    }
    if (info->si_pid != 0)
        prev_pid = info->si_pid;
    if (sig == SIGUSR2)
    {
        ch |= g_counter;
        g_counter = g_counter << 1;
        ft_printf("g_counter==%d SIGUSR2\n", g_counter);
    }
    else
    {
        g_counter = g_counter << 1;
        ft_printf("g_counter==%d SIGUSR1\n", g_counter);
    }
    usleep(200);
    if (kill(prev_pid, SIGUSR1) == -1)
        return;
}

int main()
{
    struct sigaction    act;
    sigset_t    sigset;

    ft_memset(&act, 0, sizeof(act));
    sigemptyset(&sigset);
    sigaddset(&act.sa_mask, SIGUSR2);
    sigaddset(&act.sa_mask, SIGUSR1);
    act.sa_mask = sigset;
    act.sa_flags = SIGINFO;
    act.sa_sigaction = disp;
    sigaction(SIGUSR2, &act, (void *) 0); // 1
    sigaction(SIGUSR1, &act, (void *) 0); // 0

    ft_printf("Server's PID: %d\n", getpid());

    while (1)
        pause();
    return (0);
}
