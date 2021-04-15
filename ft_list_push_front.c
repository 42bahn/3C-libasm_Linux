void	ft_list_push_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}
