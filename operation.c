/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahrach <aahrach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 09:58:31 by aahrach           #+#    #+#             */
/*   Updated: 2023/02/05 13:52:52 by aahrach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lst	**sa(t_lst **lst)
{
	int		swap;
	t_lst	*a;

	a = *lst;
	swap = a->content;
	a->content = a->next->content;
	a->next->content = swap;
	write (1, "sa\n", 3);
	return (lst);
}

void	sb(t_lst **lst)
{
	int	swap;

	if (!(*lst) || !(*lst)->next)
		return ;
	swap = (*lst)->content;
	(*lst)->content = (*lst)->next->content;
	(*lst)->next->content = swap;
	write (1, "sb\n", 3);
}

void	ra(t_lst **lst)
{
	t_lst	*p;

	if (!(*lst) || !(*lst)->next)
		return ;
	p = (*lst);
	(*lst) = (*lst)->next;
	p->next = NULL; 
	lstadd_back(lst, p);
	write (1, "ra\n", 3);
}

void	rb(t_lst **lst)
{
	t_lst	*p;

	if (!(*lst) || !(*lst)->next)
		return ;
	p = (*lst);
	(*lst) = (*lst)->next;
	p->next = NULL;
	lstadd_back(lst, p);
	write (1, "rb\n", 3);
}

void	rr(t_lst **a, t_lst **b)
{

	t_lst	*p;

	if (!(*a) || !(*a) || !(*a)->next || !(*b)->next)
		return ;
	p = (*a);
	(*a) = (*a)->next;
	p->next = NULL;
	lstadd_back(a, p);
	p = (*b);
	(*b) = (*b)->next;
	p->next = NULL;
	lstadd_back(b, p);
	write (1, "rr\n", 3);
}

void	rra(t_lst **lst)
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
	write (1, "rra\n", 4);
}

void	rrb(t_lst **lst)
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
	write (1, "rrb\n", 4);
}

void	pa(t_lst **a, t_lst **b)
{
	t_lst *p;

	if (!b)
		return ;
	p = (*b);
	(*b) = (*b)->next;
	p->next = NULL;
	lstadd_front(a, p);
	write (1, "pa\n", 3);
}

void	pb(t_lst **b, t_lst **a)
{
	t_lst *new;

	if (!a)
		return ;
	new = (*a);
	(*a) = (*a)->next;
	new->next = NULL;
	lstadd_front(b, new);
	write (1, "pb\n", 3);
}