/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 10:06:33 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/02/16 15:02:13 by rgomes-c         ###   ########.fr       */
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
	int		i;

	i = 1;
	if (ac < 2)
		ft_exit("precisa de argumentos");
	ft_check_rules(av);
	ft_is_sorted(ac, av);
	stack_a = ft_lstnew(ft_atoi(av[1]));
	while (++i < ac)
		ft_init_stack_a(&stack_a, i, av);
	return (0);
}
