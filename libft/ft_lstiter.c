#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*tmp;
	t_list	*nextnode;

	tmp = lst;
	while (tmp != NULL)
	{
		nextnode = tmp->next;
		f(tmp->content);
		tmp = nextnode;
	}
}
