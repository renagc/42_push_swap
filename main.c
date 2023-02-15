/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 10:06:33 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/02/15 17:36:04 by rgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_init_stack_a(t_list **stack_a, int i, char **av)
{
	t_list	*new_list;

	new_list = ft_lstnew(ft_atoi(av[i]));
	ft_lstadd_back(stack_a, new_list);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	int		i;

	i = 1;
	if (ac < 2)
		ft_exit("precisa de argumentos");
	ft_check_rules(av);
	stack_a = ft_lstnew(ft_atoi(av[1]));
	while (++i < ac)
		ft_init_stack_a(&stack_a, i, av);
	s(stack_a);
	while (stack_a)
	{
		printf("%d\n", stack_a->value);
		stack_a = stack_a->next;
	}
	return (0);
}
