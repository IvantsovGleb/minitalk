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

        int i = 0;
        while (argv[2][i])
        {
            int k = 0;
            while (k < (int)(sizeof(int) * 2))
            {
                if ((unsigned char)argv[2][i] & (1U << k))
                {
                    ft_printf("k(%d)=%d\n", k, 1);
                    kill(s_pid, SIGUSR2); // 1
                }
                else
                {
                    ft_printf("k(%d)=%d\n", k, 0);
                    kill(s_pid, SIGUSR1); // 0
                }
                k++;
            }
            i++;
        }
    }
    else
        ft_printf("server's PID &/or string to send is missing\n");
    return (0);
}