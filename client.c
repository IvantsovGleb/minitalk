#include "signal.h"
#include "libft/libft.h"
#include "ft_printf.h"

int main(int argc, char *argv[])
{
    pid_t   s_pid;

    if (argc == 3)
    {
        s_pid = ft_atoi(argv[1]);
        int ret = kill(s_pid, 0);
        if (ret == -1)
            ft_printf("KO: wrong pid\n");
        kill(s_pid, SIGUSR1);
    }
    else
        ft_printf("server's PID &/or string to send is missing\n");

    return (0);
}