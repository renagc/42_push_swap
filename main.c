/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 10:06:33 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/03/08 18:25:49 by rgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		i;

	i = 1;
	stack_b = 0;
	if (ac < 2)
		ft_exit("");
	ft_check_rules(av);
	ft_is_sorted(ac, av);
	stack_a = ft_lstnew(ft_atoi(av[1]));
	while (++i < ac)
		ft_init_stack_a(&stack_a, i, av);
	ft_sort_list(&stack_a, &stack_b);
	ft_free_stack(&stack_a);
	return (0);
}
