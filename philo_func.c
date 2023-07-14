#include "philosophers.h"
#include <stdlib.h>

void*   dead(void *philoo)
{
    t_data *philo;
    philo = (t_data*)philoo;
    while(1)
    {

    }
}

void*   routine(void *philoo)
{
    t_data *philo;
    philo = (t_data*)philoo;

    while(1)
    {
       if(pthread_mutex_lock(&philo->mutex_rfork) == 0)
            printf("%lu : philo %d take a fork \n", (get_time()- philo->start), philo->id);
        if(pthread_mutex_lock(&philo->next->mutex_rfork) == 0)
            printf("%lu : philo %d take a fork \n", (get_time()- philo->start), philo->id);
        printf("%lu : philo %d eatin \n", (get_time()- philo->start), philo->id);
        usleep(philo->time_to_eat * 1000);
        philo->last_meal = (get_time() - philo->start);
        pthread_mutex_unlock(&philo->mutex_rfork);
        pthread_mutex_unlock(&philo->next->mutex_rfork);
        printf("%lu : philo %d is sleepin \n", (get_time()- philo->start), philo->id);
        usleep(philo->time_to_sleep * 1000);
        printf("%lu : philo %d is thinking \n", (get_time()- philo->start), philo->id);
    }
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
    pthread_t die;
    int i = 0;
    ft_initilize(&philo, main_prog);
    philo->time_to_die = ft_atoi(main_prog->args[1]);

    t_data *last = philo;
    while((philo)->next)
        (philo) = (philo)->next;
    (philo)->next = last;
    philo = last;
    i = 1;
    while(philo && i <= ft_atoi(main_prog->args[0]))
    {
        pthread_mutex_init(&philo->mutex_rfork, NULL);
        pthread_mutex_init(&philo->mutex_death, NULL);
        philo->time_to_die = ft_atoi(main_prog->args[1]);
            philo->time_to_eat = ft_atoi(main_prog->args[2]);
    philo->time_to_sleep = ft_atoi(main_prog->args[3]);;
        i++;
        philo = philo->next;
    }
    i = 0;
    while(philo && i < ft_atoi(main_prog->args[0]))
    {
        philo->start = get_time();
        pthread_create(&t[i], NULL, &routine, philo);
        usleep(100);
        pthread_detach(t[i]);
        philo = philo->next;
        i++;
    }
    while(1)
    {
        pthread_mutex_lock(&philo->mutex_death);
        if(get_time() > philo->last_meal + philo->time_to_die)
        {
            printf("%lu : philo %d died \n", (get_time()- philo->start), philo->id);
            pthread_mutex_unlock(&philo->mutex_death);
            return;
        }
    }
}
