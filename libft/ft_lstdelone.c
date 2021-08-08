#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	t_list	*tmp;

	tmp = lst;
	lst = lst->next;
	del(tmp->content);
	free(tmp);
}
