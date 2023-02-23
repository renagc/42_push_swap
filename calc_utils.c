/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:31:45 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/02/22 21:13:48 by rgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long int	ft_sum(t_list **stack)
{
	t_list		*temp;
	long int	res;

	res = 0;
	temp = *stack;
	while (temp)
	{
		res = res + temp->value;
		temp = temp->next;
	}
	return (res);
}

long int	ft_average(t_list **stack)
{
	t_list		*temp;
	long int	res;
	long int	len;

	res = 0;
	len = 0;
	temp = *stack;
	while (temp)
	{
		res = res + temp->value;
		temp = temp->next;
		len++;
	}
	return (res / len);
}

long int	ft_max_pos(t_list **stack)
{
	t_list	*temp;
	int		max;
	int		pos;
	int		i;

	i = 0;
	pos = i;
	temp = *stack;
	max = temp->value;
	while (temp)
	{
		if (temp->value > max)
		{
			max = temp->value;
			pos = i;
		}
		i++;
		temp = temp->next;
	}
	return (pos);
}

int	ft_pos_cost_top(t_list	**stack_a, t_list **stack_b, int i)
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
