#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*tmp;

	tmp = (t_list *) ft_calloc(sizeof (t_list), 1);
	if (NULL == tmp)
		return (NULL);
	tmp->content = content;
	tmp->next = NULL;
	return ((t_list *)tmp);
}
