#include "philosophers.h"
int main(int ac, char** av) 
{
    t_push main_prog;
    int i = 0;
    char *str = ft_strdup("");
    if(ac > 1)
    {
        puts("hi");
        while (av[i])
        {
            str = ft_strjoin(str, av[i]);
            str = ft_strjoin(str, " ");
            i++;
        }
        parsing(&main_prog, str);
        philo(&main_prog);
    }
}

