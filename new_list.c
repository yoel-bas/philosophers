#include "philosophers.h"

t_list	*lst_new(int id)
{
	t_list	*p;

	p = malloc(sizeof(t_list));
	p->id = id;
	p->next = NULL;
	return (p);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

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

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (*lst && new)
	{
		new->next = (*lst);
		*lst = new;
	}
}

int	lst_size(t_list *lst)
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