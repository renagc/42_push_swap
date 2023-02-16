/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 13:01:49 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/02/16 14:41:49 by rgomes-c         ###   ########.fr       */
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

// ft_exit.c
void		ft_exit(char *msg);

// rules.c
void		ft_check_rules(char **av);

// moves.c
void		s(int *a, int *b);
void		rotate(t_list **stack);
void		rotate_reverse(t_list **stack);
void		p(t_list **stack_a, t_list **stack_b);

#endif