#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*nextnode;

	tmp = *lst;
	while (tmp != NULL)
	{
		nextnode = tmp->next;
		del(tmp->content);
		free(tmp);
		tmp = nextnode;
	}
	*lst = NULL;
}
