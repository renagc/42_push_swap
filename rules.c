/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:43:18 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/03/14 08:04:54 by rgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_check_int(const char *str)
{
	if (ft_atoi(str) > 2147483647 || ft_atoi(str) < -2147483648)
		return (0);
	return (1);
}

static int	ft_check_char(char *str)
{
	int	i;

	i = 0;
	if ((str[i] == '-' || str[i] == '+') && str[i + 1])
		i++;
	while (str[i])
	{
		if (str[i] < 48 || str[i] > 57)
			return (0);
		i++;
	}
	return (1);
}

static int	ft_check_dups(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[++i])
	{
		j = i;
		while (av[++j])
		{
			if (ft_strcmp(av[i], av[j]) == 0)
				return (0);
		}
	}
	return (1);
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
	exit(0);
}

void	ft_check_rules(char **av)
{
	int	i;

	i = 0;
	while (av[++i])
	{
		if (!ft_check_char(av[i]))
			ft_exit("");
		else if (!ft_check_int(av[i]))
			ft_exit("");
		else if (!ft_check_dups(av))
			ft_exit("");
	}
}
