/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:09:23 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/02/15 17:55:19 by rgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s(t_list *stack)
{
	t_list	*new_head;
	t_list	*current;
	t_list	*temp;

	current = stack;
	new_head = stack->next;
	temp = current->next->next;
	current->next->next = current;
	current->next = temp;
	current = temp;
	stack = new_head;
}
