#include "libft/libft.h"
#include "ft_printf.h"
#include "unistd.h"

unsigned char   ch = 0U;
unsigned char   counter = 1U;

void    disp(int signo)
{
    if (signo == SIGUSR2)
    {
        ft_printf("counter=%d ch=%d\n", counter, ch);
        ch += counter;
        counter = counter << 1U;
    }
    if (signo == SIGUSR1)
    {
        ft_printf("counter=%d ch=%d\n", counter, ch);
        counter = counter << 1U;
    }
}

int main()
{
    ft_printf("%d\n", getpid());
    signal(SIGUSR2, disp); // 1
    signal(SIGUSR1, disp); // 0
    while (1)
    {
        if (counter == 128)
        {
            write(1, &ch,1);
            ch = 0U;
            counter = 1U;
        }
    }
    return (0);
}
