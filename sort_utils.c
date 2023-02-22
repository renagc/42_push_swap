/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 23:57:29 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/02/22 12:00:01 by rgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_3(t_list **stack)
{
	int	pos;

	if (ft_lstsize(*stack) != 3)
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
	ft_sort_3(stack_a);
}

int	ft_pos_cost(t_list	**stack_a, t_list **stack_b, int i)
{
	t_list	*temp_a;
	t_list	*temp_b;
	int		moves;

	moves = 1;
	temp_a = (*stack_a);
	temp_b = (*stack_b);
	while (i--)
	{
		temp_b = temp_b->next;
		moves++;
	}
	while (temp_b->value > temp_a->value)
	{
		moves++;
		temp_a = temp_a->next;
	}
	return (moves);
}

int	ft_pos_min_cost(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp_a;
	t_list	*temp_b;
	int		min;
	int		cost;
	int		pos;

	temp_a = *stack_a;
	temp_b = *stack_b;
	pos = 1;
	min = 0;
	cost = ft_pos_cost(&temp_a, &temp_b, 0);
	while (pos < (ft_lstsize(temp_b) - 3))
	{
		if (cost > ft_pos_cost(&temp_a, &temp_b, pos))
		{
			cost = ft_pos_cost(&temp_a, &temp_b, pos);
			min = pos;
		}
		pos++;
	}
	return (min);
}

void	ft_p_to_a(t_list **stack_a, t_list **stack_b)
{
	int		moves_stack_a;
	int		pos;

	moves_stack_a = 0;
	pos = ft_pos_min_cost(stack_a, stack_b);
	while ((*stack_b))
	{
		while (pos-- > 0)
			rotate(stack_b, "rb");
		while ((*stack_b)->value > (*stack_a)->value)
		{
			rotate(stack_a, "ra");
			moves_stack_a++;
		}
		p(stack_a, stack_b, "pa");
		while (moves_stack_a > 0)
		{
			rotate_reverse(stack_a, "rra");
			moves_stack_a--;
		}
		if ((*stack_b))
			pos = ft_pos_min_cost(stack_a, stack_b);
		ft_sort_3(stack_b);
	}
}
