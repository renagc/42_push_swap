/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:09:23 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/03/14 15:15:36 by rgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//inicia a stack
void	ft_init_stack_a(t_list **stack_a, int i, char **av)
{
	t_list	*new_list;

	new_list = ft_lstnew(ft_atoi(av[i]));
	ft_lstadd_back(stack_a, new_list);
}

//faz swap dos primeiros
void	s(int *a, int *b, char *str)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
	if (str)
		ft_printf("%s\n", str);
}

//primeiro passa a ultimo
void	rotate(t_list **stack, char *str)
{
	t_list	*first;
	t_list	*last;

	first = (*stack)->next;
	last = ft_lstlast(*stack);
	last->next = *stack;
	(*stack)->next = NULL;
	*stack = first;
	if (str)
		ft_printf("%s\n", str);
}

//ultimo passa a primeiro
void	rotate_reverse(t_list **stack, char *str)
{
	t_list	*first;
	t_list	*last;

	last = *stack;
	first = ft_lstlast(*stack);
	if (last->next->next == NULL)
	{
		s(&last->value, &last->next->value, 0);
		(*stack) = last;
	}
	else
	{
		while (last->next->next != NULL)
			last = last->next;
		last->next = NULL;
		first->next = *stack;
		*stack = first;
	}
	ft_printf("%s\n", str);
}

//primeiro elemento que estiver na b
void	p(t_list **stack_a, t_list **stack_b, char *str)
{
	t_list	*first_a;
	t_list	*first_b;

	if (!(*stack_b))
		return ;
	first_a = (*stack_b);
	first_b = (*stack_b)->next;
	first_a->next = (*stack_a);
	*stack_a = first_a;
	*stack_b = first_b;
	ft_printf("%s\n", str);
}
