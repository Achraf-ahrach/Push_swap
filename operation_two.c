/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahrach <aahrach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:41:21 by aahrach           #+#    #+#             */
/*   Updated: 2023/02/06 23:35:09 by aahrach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_lst **lst, int k)
{
	t_lst	*p;
	t_lst	*new;

	if (!(*lst) || !(*lst)->next)
		return ;
	p = (*lst);
	while (p->next->next)
		p = p->next;
	new = p->next;
	p->next = NULL;
	lstadd_front(lst, new);
	if (k)
		write (1, "rra\n", 4);
}

void	rrb(t_lst **lst, int k)
{
	t_lst	*p;
	t_lst	*new;

	if (!(*lst) || !(*lst)->next)
		return ;
	p = (*lst);
	while (p->next->next)
		p = p->next;
	new = p->next;
	p->next = NULL;
	lstadd_front(lst, new);
	if (k)
		write (1, "rrb\n", 4);
}

void	pa(t_lst **a, t_lst **b, int k)
{
	t_lst	*p;

	if (!b || !*b)
		return ;
	p = (*b);
	(*b) = (*b)->next;
	p->next = NULL;
	lstadd_front(a, p);
	if (k)
		write (1, "pa\n", 3);
}

void	pb(t_lst **b, t_lst **a, int k)
{
	t_lst	*new;

	if (!a || !*a)
		return ;
	new = (*a);
	(*a) = (*a)->next;
	new->next = NULL;
	lstadd_front(b, new);
	if (k)
		write (1, "pb\n", 3);
}

void	ss(t_lst *stack_a, t_lst *stack_b)
{
	int		swap;

	if (!stack_a || !stack_b || !stack_a->next || !stack_b->next)
		return ;
	swap = stack_a->content;
	stack_a->content = stack_a->next->content;
	stack_a->next->content = swap;
	swap = stack_b->content;
	stack_b->content = stack_b->next->content;
	stack_b->next->content = swap;
}
