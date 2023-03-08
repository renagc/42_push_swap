#include "push_swap.h"

char	*ft_checker(t_list **stack_a, t_list **stack_b)
{
	while (*stack_a)
	{
		if ((*stack_a)->next && (*stack_a)->value > (*stack_a)->next->value)
			return ("KO");
		*stack_a = (*stack_a)->next;
	}
	if (!stack_b)
		return ("KO");
	return ("OK");
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
	ft_printf("%s\n", ft_checker(&stack_a, &stack_b));
	ft_free_stack(&stack_a);
	return (0);
}
