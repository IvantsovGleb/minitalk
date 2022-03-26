#include "signal.h"
#include "libft/libft.h"

int main(int argc, char *argv[])
{
    pid_t   s_pid;

    if (argc == 3)
    {
        s_pid = ft_atoi(argv[1]);
        kill(s_pid, SIGUSR1);
    }
    return (0);
}