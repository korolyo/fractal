#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*nextnode;
	t_list	*newlist;
	t_list	*head;

	if (lst == NULL)
		return (NULL);
	tmp = lst;
	head = ft_lstnew(f(tmp->content));
	while (tmp->next != NULL)
	{
		nextnode = tmp->next;
		newlist = ft_lstnew(f(nextnode->content));
		if (newlist == NULL)
		{
			ft_lstclear(&newlist, del);
			ft_lstclear(&head, del);
			return (NULL);
		}
		ft_lstadd_back(&head, newlist);
		tmp = nextnode;
	}
	return (head);
}
