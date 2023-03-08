/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:31:45 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/03/08 17:24:59 by rgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long int	ft_sum(t_list **stack)
{
	t_list			*temp;
	long long int	res;

	res = 0;
	temp = *stack;
	while (temp)
	{
		res = res + temp->value;
		temp = temp->next;
	}
	return (res);
}

long long int	ft_average(t_list **stack)
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

long long int	ft_max_pos(t_list **stack)
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

t_list	*ft_stack_min(t_list **stack)
{
	t_list	*temp;
	t_list	*min;

	min = (*stack);
	temp = (*stack);
	while (temp)
	{
		if (temp->value < min->value)
			min = temp;
		temp = temp->next;
	}
	return (min);
}
