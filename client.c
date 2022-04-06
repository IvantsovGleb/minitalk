#include <signal.h>
#include "libft/libft.h"
#include "ft_printf.h"

void    answer(int sig)
{
    (void)sig;
    ft_printf("\n");
}

void    send_str(pid_t pid, char *str)
{
    int i;
    int k;

    i = 0;
    while (str[i])
    {
        k = 0;
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
            usleep(100);
            k++;
        }
        i++;
    }
}

int main(int argc, char *argv[])
{
    pid_t   pid;

    signal(SIGUSR1, answer);
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