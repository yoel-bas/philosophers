#include "philosophers.h"
void       data_setup(t_push *main_prog, t_data **data)
{
    	(*data)->num_ph = ft_atoi(main_prog->args[0]);
		(*data)->time_to_die = ft_atoi(main_prog->args[1]);
		(*data)->time_to_eat = ft_atoi(main_prog->args[2]);
		(*data)->time_to_sleep = ft_atoi(main_prog->args[3]);
        if(main_prog->args[4])
        (*data)->count = ft_atoi(main_prog->args[4]);
}
void*   routine(void *philoo)
{
    t_philo *philo;
    philo = (t_philo*)philoo;
    if(philo->id % 2)
        usleep(100);
    while(1)
    {
        if(pthread_mutex_lock(&philo->mutex_rfork) == 0)
            ft_print(philo, "has taken a left fork");
        if(pthread_mutex_lock(&philo->next->mutex_rfork) == 0)
            ft_print(philo, "has taken a right fork");
        ft_print(philo, "is eating");
        if(pthread_mutex_lock(&philo->mutex_eat) == 0)
        philo->time_eat++;
        pthread_mutex_unlock(&philo->mutex_eat);
        philo->last_meal = get_time();
        if(philo->time_eat == philo->data->count)
            philo->data->meal++;
        usleep(philo->data->time_to_eat  * 1000);
        pthread_mutex_unlock(&philo->next->mutex_rfork);
        pthread_mutex_unlock(&philo->mutex_rfork);
        ft_print(philo, "is sleeping");
        usleep(philo->data->time_to_sleep * 1000);
        ft_print(philo, "is thinking");
    }
}
void     intialize_list(t_philo **a,t_push *main_prog, t_data *data)
{
    int	i;
	i = 1;
	while (i <= ft_atoi(main_prog->args[0]))
	{
		if (i == 1)
			(*a) = lst_new(i, (data));
		else
			ft_lstadd_back(a, lst_new(i, (data)));
		i++;
	}
   
}
void	ft_mutex_init(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->data->num_ph)
	{
		if (pthread_mutex_init(&philo->mutex_rfork, NULL) != 0)
			return ;
		if (pthread_mutex_init(&philo->mutex_eat, NULL) != 0)
			return ;
		i++;
		philo = philo->next;
	}
	if (pthread_mutex_init(&philo->data->mutex_print, NULL))
		return ;
	if (pthread_mutex_init(&philo->data->mutex_death, NULL))
		return ;
}
int        check_death(t_philo *philo)
{
    while(1)
    {
        if(philo->data->meal == philo->data->count)
            return(1);
        pthread_mutex_lock(&philo->data->mutex_death);
        if(get_time() - philo->last_meal > philo->data->time_to_die)
        {
            ft_print(philo, "died");
            return(1);
        }
        pthread_mutex_unlock(&philo->data->mutex_death);
        philo = philo->next;
    }
}
void	create_thread(t_philo *philo)
{
	int	i;
	philo->data->start = get_time();
	i = 0;
	while (i < philo->data->num_ph)
	{
		philo->last_meal = get_time();
        philo->time_eat = 0;
		pthread_create(&philo->thread, NULL, routine, philo);
		pthread_detach(philo->thread);
		philo = philo->next;
		i++;
	}
}

int        philo(t_push *main_prog)
{
    t_philo *philo = malloc(sizeof(philo));
    t_data *data = malloc(sizeof(t_data));
    data_setup(main_prog,&data);
    intialize_list(&philo, main_prog, data);
    t_philo *last = philo;
    while((philo)->next)
        (philo) = (philo)->next;
    (philo)->next = last;

    philo = last;
    ft_mutex_init(philo);
    create_thread(philo);
    if(check_death(philo))
    {
        return(1);
    }
        free(main_prog);
        free(philo);
    return(0);
}   