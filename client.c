#include <signal.h>
#include "libft/libft.h"
#include "ft_printf.h"

int g_notification;

void    answer(int sig, siginfo_t *info, void *ucontext)
{
    (void)sig;
    (void)info;
    (void)ucontext;
    ft_printf("\n");
    g_notification = 1;
}

void    send_str(pid_t pid, char *str)
{
    int i;
    int k;

    i = 0;
    while (str[i])
    {
        k = 0;
        g_notification = 0;
        while (k < (int)(sizeof(int) * 2))
        {
            if ((unsigned char)str[i] & (1 << k))
            {
                kill(pid, SIGUSR2); // 1
            }
            else
            {
                kill(pid, SIGUSR1); // 0
            }
            while (g_notification != 1)
                ;
            k++;
        }
        i++;
    }
}

int main(int argc, char *argv[])
{
    pid_t   pid;
    struct sigaction    act;
    sigset_t    sigset;

    sigemptyset(&sigset);
    ft_memset(&act, 0, sizeof(act));
    sigemptyset(&act.sa_mask);
    act.sa_flags = SIGINFO;
    act.sa_sigaction = answer;
    sigaction(SIGUSR1, &act, (void *) 0);

    if (argc == 3)
    {
        pid = ft_atoi(argv[1]);
        int ret = kill(pid, 0);
        if (ret == -1)
            ft_printf("KO: wrong pid\n");
        ft_printf("Client's PID: %d\n", getpid());
        send_str(pid, argv[2]);
    }
    else
        ft_printf("server's PID &/or string to send is missing\n");
    sleep(10);
    return (0);
}