/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_one.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahrach <aahrach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 09:58:31 by aahrach           #+#    #+#             */
/*   Updated: 2023/02/06 23:34:03 by aahrach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lst	**sa(t_lst **lst, int k)
{
	int		swap;
	t_lst	*a;

	if (!(*lst) || !(*lst)->next)
		return (NULL);
	a = *lst;
	swap = a->content;
	a->content = a->next->content;
	a->next->content = swap;
	if (k)
		write (1, "sa\n", 3);
	return (lst);
}

void	sb(t_lst **lst, int k)
{
	int	swap;

	if (!(*lst) || !(*lst)->next)
		return ;
	swap = (*lst)->content;
	(*lst)->content = (*lst)->next->content;
	(*lst)->next->content = swap;
	if (k)
		write (1, "sb\n", 3);
}

void	ra(t_lst **lst, int k)
{
	t_lst	*p;

	if (!(*lst) || !(*lst)->next)
		return ;
	p = (*lst);
	(*lst) = (*lst)->next;
	p->next = NULL;
	lstadd_back(lst, p);
	if (k)
		write (1, "ra\n", 3);
}

void	rb(t_lst **lst, int k)
{
	t_lst	*p;

	if (!(*lst) || !(*lst)->next)
		return ;
	p = (*lst);
	(*lst) = (*lst)->next;
	p->next = NULL;
	lstadd_back(lst, p);
	if (k)
		write (1, "rb\n", 3);
}

void	rr(t_lst **a, t_lst **b, int k)
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
	if (k)
		write (1, "rr\n", 3);
}
