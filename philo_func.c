#include "philosophers.h"
#include <stdlib.h>
void*   routine(void *philoo)
{
    t_push *main_prog = NULL;
    unsigned long start = get_time();
    main_prog = malloc(sizeof(t_push *));
    t_data *philo = (t_data *)(philoo);
    philo->last_meal = 0;
    pthread_mutex_init(&philo->mutex_rfork, NULL);
    while (1)
    {
        if((philo->id % 2) != 0)
            usleep((philo->time_to_eat / 2) * 1000);
        pthread_mutex_lock(&philo->mutex_rfork);
        printf("%lu : philo %d has taken a fork \n",(get_time() - start), philo->id);
        pthread_mutex_lock(&philo->next->mutex_rfork);
        printf("%lu : philo %d has taken a fork \n",(get_time() - start),  philo->id);
        printf("%lu : philo %d eats \n",(get_time() - start), philo->id);
        philo->last_meal = ((get_time() - start));
        usleep((philo->time_to_sleep) * 1000);
        pthread_mutex_unlock(&philo->mutex_rfork);
        pthread_mutex_unlock(&philo->next->mutex_rfork);
        printf("%lu : philo %d is sleepin \n",(get_time() - start),  philo->id);
        usleep((philo->time_to_sleep) * 1000);
        printf("%lu : philo %d is thinkin \n",(get_time() - start),  philo->id);
        if(philo->time_to_die < philo->last_meal)
        {
        printf("%lu : philo %d dies  \n",(get_time() - start),  philo->id);
        exit(1);
        }
        philo = philo->next;
    }
    return(NULL);
}
void	ft_initilize(t_data **a, t_push *main_prog)
{
	int	i;

	i = 1;
	while (i <= ft_atoi(main_prog->args[0]))
	{
		if (i == 1)
			(*a) = lst_new(i);
		else
			ft_lstadd_back(a, lst_new(i));
		i++;
	}

}
void    philo(t_push *main_prog)
{
    t_data *philo = NULL;
    philo = malloc(sizeof(t_data));
    pthread_t t[ft_atoi(main_prog->args[0])];
    int i = 0;
    ft_initilize(&philo, main_prog);
    philo->time_to_die = ft_atoi(main_prog->args[1]);
    philo->time_to_eat = ft_atoi(main_prog->args[2]);
    philo->time_to_sleep = ft_atoi(main_prog->args[3]);
    t_data *last = philo;
    while((philo)->next)
        (philo) = (philo)->next;
    (philo)->next = last;
    philo = last;
    i = 1;
    philo->time_to_die = ft_atoi(main_prog->args[1]);
    while(i <= ft_atoi(main_prog->args[0]))
    {
        pthread_create(&t[i], NULL, &routine, philo);
        pthread_join(t[i], NULL);
        i++;
    }
}
