/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 10:06:33 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/02/22 12:02:45 by rgomes-c         ###   ########.fr       */
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
	t_list	*temp_b;
	t_list	*new_last;
	int		i;

	stack_b = ft_lstnew(0);
	i = 1;
	if (ac < 2)
		ft_exit("");
	ft_check_rules(av);
	ft_is_sorted(ac, av);
	stack_a = ft_lstnew(ft_atoi(av[1]));
	while (++i < ac)
		ft_init_stack_a(&stack_a, i, av);
	if (ft_lstsize(stack_a) == 3)
		ft_sort_3(&stack_a);
	else
		ft_ave_to_b(&stack_a, &stack_b);
	temp_b = stack_b;
	while (temp_b->next != NULL)
		temp_b = temp_b->next;
	new_last = stack_b;
	while (new_last->next->next != NULL)
		new_last = new_last->next;
	new_last->next = NULL;
	free(temp_b);
	return (0);
}
