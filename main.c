/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 10:06:33 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/03/06 17:03:21 by rgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_init_stack_a(t_list **stack_a, int i, char **av)
{
	t_list	*new_list;

	new_list = ft_lstnew(ft_atoi(av[i]));
	ft_lstadd_back(stack_a, new_list);
}

void	ft_is_sorted(int ac, char **av)
{
	int	i;

	i = 0;
	while (++i < ac)
	{
		if ((i + 1 < ac) && (ft_atoi(av[i]) > ft_atoi(av[i + 1])))
			return ;
	}
	ft_exit("ja esta sorted");
}

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
	return (0);
}
