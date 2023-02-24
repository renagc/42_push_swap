/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:56:40 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/02/23 20:47:31 by rgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_stack_from_bottom(t_list **stack)
{
	t_list	*new_stack;
	t_list	*temp;
	t_list	*new_list;

	temp = (*stack);
	new_stack = ft_lstnew(temp->value);
	temp = temp->next;
	while (temp)
	{
		new_list = ft_lstnew(temp->value);
		ft_lstadd_front(&new_stack, new_list);
		temp = temp->next;
	}
	return (new_stack);
}

int	ft_pos_top_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp_a;
	t_list	*stack_a_from_bottom;
	t_list	*temp_b;
	int		half_size;
	int		i;

	stack_a = (*stack_a);
	stack_b = (*stack_b);
	half_size = ft_lstsize(temp_a);
	if (half_size % 2 != 0)
		half_size++;
	half_size /= 2;
	i = 0;
	while (i < half_size)
	{
		
	}
}
