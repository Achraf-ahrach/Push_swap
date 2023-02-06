/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahrach <aahrach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 17:49:08 by aahrach           #+#    #+#             */
/*   Updated: 2023/02/06 23:19:14 by aahrach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_lst{
	int				content;
	int				index;
	struct s_lst	*next;
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
void	ft_error_lst(t_lst *p, int k);
void	push_swap(t_lst **stack_a);
t_lst	**sa(t_lst **lst, int k);
void	sb(t_lst **lst, int k);
void	ra(t_lst **lst, int k);
void	rb(t_lst **lst, int k);
void	rra(t_lst **lst, int k);
void	rrb(t_lst **lst, int k);
void	pa(t_lst **a, t_lst **b, int k);
void	pb(t_lst **b, t_lst **a, int k);
void	rr(t_lst **a, t_lst **b, int k);
int		acses(t_lst *stack_a);
void	three(t_lst **a);
void	rank(int min, t_lst *stack_a);
void	five(t_lst **stack_a, t_lst **b);
int		srch_idx(t_lst *stack_b, int index);
void	initialize_index(t_lst **stack_a, int max_index);
void	initializ_one(t_lst *stack_a);
void	one_hundred(t_lst **stack_a, t_lst **stack_b);
void	five_hundred(t_lst **stack_a, t_lst **stack_b);
t_lst	*max_ele(t_lst *t);
#endif