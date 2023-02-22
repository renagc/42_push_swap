/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 13:01:49 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/02/22 11:28:43 by rgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// ------------------------------- INCLUDES --------------------------------- //

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "ft_printf/ft_printf.h"

// -------------------------------- MACROS ---------------------------------- //

// ------------------------------- STRUCTS ---------------------------------- //

typedef struct t_list {
	int				value;
	struct t_list	*next;
}t_list;

// -----------------------------  FUNCTIONS --------------------------------- //

// libft_utils.c
long int	ft_atoi(const char *str);
int			ft_strcmp(const char *s1, const char *s2);

// list_utils.c
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstnew(int data);
void		ft_lstadd_back(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
void		ft_lst_print(t_list **stack);

// ft_exit.c
void		ft_exit(char *msg);

// rules.c
void		ft_check_rules(char **av);

// moves.c
void		s(int *a, int *b, char *str);
void		rotate(t_list **stack, char *str);
void		rotate_reverse(t_list **stack, char *str);
void		p(t_list **stack_a, t_list **stack_b, char *str);

// calc_utils.c
long int	ft_sum(t_list **stack);
long int	ft_average(t_list **stack);
long int	ft_max_pos(t_list **stack);

// sort_utils.c
void		ft_sort_3(t_list **stack);
void		ft_ave_to_b(t_list **stack_a, t_list **stack_b);
int			ft_pos_cost(t_list	**stack_a, t_list **stack_b, int i);
int			ft_pos_min_cost(t_list **stack_a, t_list **stack_b);
void		ft_p_to_a(t_list **stack_a, t_list **stack_b);

#endif