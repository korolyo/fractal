#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*final;

	if (!lst && !new)
		return ;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	final = *lst;
	while (final->next != NULL)
		final = final->next;
	final->next = new;
}
