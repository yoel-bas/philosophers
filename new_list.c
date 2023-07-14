

#include "philosophers.h"

t_data	*lst_new(int content)
{
	t_data	*p;

	p = malloc(sizeof(t_data));
	p->id = content;
	p->next = NULL;
	return (p);
}

void	ft_lstadd_back(t_data **lst, t_data *new)
{
	t_data	*last;

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

void	ft_lstadd_front(t_data **lst, t_data *new)
{
	if (*lst && new)
	{
		new->next = (*lst);
		*lst = new;
	}
}

int	lst_size(t_data *lst)
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
