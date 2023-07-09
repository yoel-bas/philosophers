#include "philosophers.h"
void    ft_init(t_list **philo, t_push *main_prog)
{
    int i = 1;
    int n = ft_atoi(main_prog->args[1]);
    while(i <= n)
    {
        main_prog->philo_id->id[]
    }
}
void*    routine(void *philo)
{

    printf("%d\n", philo_id->id);
    return(NULL);
}
void        philo(t_push *main_prog)
{

    // int n = ft_atoi(main_prog->args[1]);
    // pthread_t t[n];
    t_list **philo = NULL;
    puts("CDSCDC");
    ft_init(philo, main_prog);
    while((*philo))
    {
        printf("%d\n", (*philo)->id);
        (*philo) = (*philo)->next;
    }
    // while(n)
    // {
    //     pthread_create(&t[n], NULL, &routine, *philo);
    //     pthread_join(t[n], NULL);
    //     (*philo) = (*philo)->next;
    //     n--;
    // } 

}
