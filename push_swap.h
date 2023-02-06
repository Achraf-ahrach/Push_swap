/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahrach <aahrach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 17:49:08 by aahrach           #+#    #+#             */
/*   Updated: 2023/02/05 20:20:39 by aahrach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_lst{
	int content;
	int	index;
	struct s_lst *next;
}	t_lst;

int		ft_strlen(char *s);
int		ft_atoi(char *str, t_lst *p);
char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(char *s, char c);
t_lst	*lstnew(int content);
t_lst	*lstlast(t_lst *lst);
void	lstadd_back(t_lst **lst, t_lst *new);
void	lstadd_front(t_lst **list, t_lst *new);
int		lstsize(t_lst **lst);
void	ft_error_lst(t_lst *p);
void	push_swap(t_lst **stack_a);
t_lst	**sa(t_lst **lst);
void	sb(t_lst **lst);
void	ra(t_lst **lst);
void	rb(t_lst **lst);
void	rra(t_lst **lst);
void	rrb(t_lst **lst);
void	pa(t_lst **a, t_lst **b);
void	pb(t_lst **b, t_lst **a);
void	rr(t_lst **a, t_lst **b);
int		acses(t_lst *stack_a);
void	three(t_lst **a);
void	five(t_lst **stack_a, t_lst **b);
void	one_hundred(t_lst **stack_a, t_lst **stack_b);
void	five_hundred(t_lst **stack_a, t_lst **stack_b);
t_lst *max_ele(t_lst *t);
#endif