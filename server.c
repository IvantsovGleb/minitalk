#include "libft/libft.h"
#include "ft_printf.h"
#include "unistd.h"

void    receive_sig(int sig)
{
    if (sig == SIGUSR1)
    {
        ft_printf("Received SIGUSR1!\n");
    }
    else if (sig == SIGUSR2)
    {
        ft_printf("Received SIGUSR2!\n");
    }
}

int main()
{
    ft_printf("%d\n", getpid());
    signal(SIGUSR1, receive_sig);
    while (1)
        ;
    return (0);
}