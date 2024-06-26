/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 23:57:29 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/03/14 15:30:26 by rgomes-c         ###   ########.fr       */
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
	while (stack_a && ft_lstsize(*stack_a) > 3 && stack_b)
	{
		if ((*stack_a)->value < ft_average(stack_a))
		{
			p(stack_b, stack_a, "pb");
			if ((*stack_b)->value < ft_average(stack_b)
				&& ft_lstsize(*stack_b) - 3)
				rotate(stack_b, "rb");
		}
		else
			rotate(stack_a, "ra");
	}
}

void	ft_push_fit_top(t_list **stack, t_list *best_friend, char *str)
{
	if (ft_lstsize(best_friend) > (ft_lstsize(*stack) / 2))
	{
		while (*stack != best_friend)
		{
			if (str[0] == 'a')
				rotate(stack, "ra");
			else if (str[0] == 'b')
				rotate(stack, "rb");
		}
	}
	else
	{
		while (*stack != best_friend)
		{
			if (str[0] == 'a')
				rotate_reverse(stack, "rra");
			else if (str[0] == 'b')
				rotate_reverse(stack, "rrb");
		}
	}
}

void	ft_sort_last_two(t_list **stack_a, t_list **stack_b)
{
	if ((*stack_b)->value < (*stack_b)->next->value)
		s(&(*stack_b)->value, &(*stack_b)->next->value, "sb");
	ft_push_fit_top(stack_a, ft_best_friend(stack_a, stack_b), "a");
	p(stack_a, stack_b, "pa");
	ft_push_fit_top(stack_a, ft_best_friend(stack_a, stack_b), "a");
	p(stack_a, stack_b, "pa");
}

void	ft_sort_list(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) <= 3)
		ft_sort_3(stack_a);
	else
	{
		ft_ave_to_b(stack_a, stack_b);
		ft_sort_3(stack_a);
		while (*stack_b && ft_lstsize(*stack_b) > 2)
		{
			ft_push_fit_top(stack_b, ft_get_min_cost_b(stack_a, stack_b), "b");
			ft_push_fit_top(stack_a, ft_best_friend(stack_a, stack_b), "a");
			p(stack_a, stack_b, "pa");
		}
		ft_sort_last_two(stack_a, stack_b);
		ft_push_fit_top(stack_a, ft_stack_min(stack_a), "a");
	}
}
