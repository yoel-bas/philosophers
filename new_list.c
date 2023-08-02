

#include "philosophers.h"

t_philo	*lst_new(int content, t_data *data)
{
	t_philo	*p;

	p = malloc(sizeof(t_philo));
	p->id = content;
	p->next = NULL;
	p->data = data;
	return (p);
}

void	ft_lstadd_back(t_philo **lst, t_philo *new)
{
	t_philo	*last;

	last = *lst;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new;
}

void	ft_lstadd_front(t_philo **lst, t_philo *new)
{
	if (*lst && new)
	{
		new->next = (*lst);
		*lst = new;
	}
}

int	lst_size(t_philo *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
