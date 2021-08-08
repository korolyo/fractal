#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new && !*lst)
		return ;
	else if (lst == 0)
		*lst = new;
	else
	{
		new->next = (*lst);
		(*lst) = new;
	}
}
