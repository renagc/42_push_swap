/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 23:57:29 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/03/06 20:59:02 by rgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_3(t_list **stack)
{
	int	pos;

	if (ft_lstsize(*stack) > 3)
		return ;
	pos = ft_max_pos(stack);
	if (pos == 0)
		rotate(stack, "ra");
	else if (pos == 1)
		rotate_reverse(stack, "rra");
	if ((*stack)->value > (*stack)->next->value)
		s(&(*stack)->value, &(*stack)->next->value, "sa");
}

void	ft_ave_to_b(t_list **stack_a, t_list **stack_b)
{
	while (stack_a && ft_lstsize(*stack_a) != 3)
	{
		if ((*stack_a)->value < ft_average(stack_a))
			p(stack_b, stack_a, "pb");
		else
			rotate(stack_a, "ra");
	}
}

void	ft_push_fit_top(t_list **stack, t_list **min_cost)
{
	t_list	*current;

	current = (*stack);
	if (ft_lstsize(*min_cost) < (ft_lstsize(*stack) / 2))
	{
		while (current != (*min_cost))
		{
			rotate(stack, "ra");
			current = (*stack);
		}
	}
	else
	{
		while (current != (*min_cost))
		{
			rotate_reverse(stack, "rra");
			current = (*stack);
		}
	}
}

void	ft_sort_list(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	if (ft_lstsize(*stack_a) <= 3)
		ft_sort_3(stack_a);
	else
	{
		ft_ave_to_b(stack_a, stack_b);
		ft_sort_3(stack_a);
		while (*stack_b)
		{
			temp = ft_get_min_cost_b(stack_a, stack_b);
			ft_push_fit_top(stack_b, &temp);
			temp = ft_min_cost_a(stack_a, stack_b);
			ft_push_fit_top(stack_a, &temp);
			p(stack_a, stack_b, "pa");
		}
	}
}
