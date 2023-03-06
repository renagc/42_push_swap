/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:56:40 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/03/06 17:33:03 by rgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//diz o elemento que tem custo minimo da stack b
t_list	*ft_get_min_cost_b(t_list **stack_a, t_list **stack_b)
{
	int		cost;
	int		min;
	int		pos;
	t_list	*min_cost_b;
	t_list	*temp_b;

	pos = 0;
	min_cost_b = 0;
	min = 2147483647;
	temp_b = (*stack_b);
	while (temp_b && ++pos)
	{
		if (pos <= (ft_lstsize(temp_b) / 2))
			cost = ft_lstsize(*stack_b) - ft_lstsize(temp_b)
				+ ft_get_pos_a(stack_a, &temp_b);
		else
			cost = ft_lstsize(temp_b) + ft_get_pos_a(stack_a, &temp_b);
		if (cost < min)
		{
			min = cost;
			min_cost_b = temp_b;
		}
		temp_b = temp_b->next;
	}
	return (min_cost_b);
}


//diz se está em cima da stack ou do meio para baixo da stack a
int	ft_get_pos_a(t_list **stack, t_list **current)
{
	int		temp;
	t_list	*temp_stack;

	temp_stack = ft_min_cost_a(stack, current);
	temp = 0;
	if (ft_lstsize(temp_stack) < (ft_lstsize(*stack) / 2))
		temp = ft_lstsize(temp_stack);
	else
		temp = ft_lstsize(*stack) - ft_lstsize(temp_stack);
	return (temp);
}

//percorre stack a e verifica o best friend do top b
t_list	*ft_min_cost_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;
	t_list	*min_cost;
	int		dif;

	dif = 2147483647;
	min_cost = 0;
	temp = *stack_a;
	if (!(*stack_b))
		return (0);
	while (temp)
	{
		if (temp->value > (*stack_b)->value
			&& (temp->value - (*stack_b)->value) < dif)
		{
			min_cost = temp;
			dif = temp->value - (*stack_b)->value;
		}
		temp = temp->next;
	}
	return (min_cost);
}
