#include <unistd.h>
#include <signal.h>
#include "libft/libft.h"
#include "ft_printf.h"

unsigned char    ch = 0;
int     counter = 1;

void    one(int sig, siginfo_t *info, void *ucontext)
{
    ft_printf("counter=%d ch=%d\n", counter, ch);

    (void)sig;
    (void)ucontext;
    ch |= counter;
    counter = counter << 1;
    if (counter == 128)
    {
        write(1, &ch,1);
        ch = 0;
        counter = 1;
        ft_printf("Client's PID: %d\n", info->si_pid);
        if (kill(info->si_pid, 0))
            kill(info->si_pid, SIGUSR1);
        else
            ft_printf("There is no client with such PID\n");
    }
}

void    zero(int sig, siginfo_t *info, void *ucontext)
{
    ft_printf("counter=%d ch=%d\n", counter, ch);

    (void)sig;
    (void)ucontext;
    counter = counter << 1;
    if (counter == 128)
    {
        write(1, &ch,1);
        ch = 0;
        counter = 1;
        ft_printf("Client's PID: %d\n", info->si_pid);
        if (kill(info->si_pid, 0))
            kill(info->si_pid, SIGUSR1);
        else
            ft_printf("There is no client with such PID\n");
    }
}

int main()
{
    struct sigaction    act0;
    struct sigaction    act1;
    sigset_t    sigset;

    sigemptyset(&sigset);
    ft_memset(&act0, 0, sizeof(act0));
    ft_memset(&act1, 0, sizeof(act1));

    act0.sa_flags = SIGINFO;
    act0.sa_sigaction = one;
    sigaddset(&act0.sa_mask, SIGUSR1);
    sigaction(SIGUSR1, &act0, (void *) 0); // 0

    act1.sa_flags = SIGINFO;
    act1.sa_sigaction = zero;
    sigaddset(&act1.sa_mask, SIGUSR2);
    sigaction(SIGUSR2, &act1, (void *) 0); // 1

    ft_printf("Server's PID: %d\n", getpid());

    while (1)
        ;
    return (0);
}
