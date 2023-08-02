#include "philosophers.h"

int main(int ac, char** av) 
{
    t_push main_prog;
    int i = 1;
    char *str = ft_strdup("");
    if(ac == 5 || ac == 6)
    {
        while (av[i])
        {
            str = ft_strjoin(str, av[i]);
            str = ft_strjoin(str, " ");
            i++;
        }
        parsing(&main_prog, str);
       if(philo(&main_prog))
            return(1);
        while(1)
        {}
    }
    return(0);
}