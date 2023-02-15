/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 10:03:39 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/02/15 12:57:07 by rgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*temp;

	if (!lst)
		return (lst);
	temp = lst;
	while (temp->next)
		temp = temp->next;
	return (temp);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*lastlist;
	t_list	*initlist;

	initlist = (*lst);
	if (!(*lst))
		*lst = new;
	else
	{
		lastlist = ft_lstlast(*lst);
		lastlist -> next = new;
	}
	*lst = initlist;
}

t_list	*ft_lstnew(int data)
{
	t_list	*newlist;

	newlist = malloc(sizeof(t_list));
	if (!newlist)
		return (0);
	newlist->value = data;
	newlist->next = NULL;
	return (newlist);
}