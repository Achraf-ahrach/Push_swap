/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_hundred.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahrach <aahrach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 19:08:03 by aahrach           #+#    #+#             */
/*   Updated: 2023/02/07 00:05:02 by aahrach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_there_more(t_lst *list, int start, int end)
{
	while (list)
	{
		if (list->index >= start && list->index <= end)
			return (1);
		list = list->next;
	}
	return (0);
}

void	fdividing_stack_a(t_lst **stack_a, t_lst **stack_b, int start, int end)
{
	while (is_there_more(*stack_a, start, end))
	{
		if ((*stack_a)->index >= start && (*stack_a)->index <= end)
		{
			if (lstsize(stack_b)
				&& (*stack_a)->index <= start + (end - start) / 2)
			{
				pb(stack_b, stack_a, 1);
				if (*stack_a && ((*stack_a)->index > end
						|| (*stack_a)->index < start))
					rr(stack_a, stack_b, 1);
				else
					rb(stack_b, 1);
			}
			else
				pb(stack_b, stack_a, 1);
		}
		else
			ra(stack_a, 1);
	}
}

void	push_max(t_lst **stack_a, t_lst **stack_b)
{
	while (*stack_b)
	{
		if ((*stack_b)->index == lstsize(stack_b) - 1)
		{
			pa(stack_a, stack_b, 1);
			return ;
		}
		else
			rb(stack_b, 1);
	}
}

void	fonction_help(t_lst **a, t_lst **b, int size)
{
	while (*b || acses(*a) == -1)
	{
		if (*b && (*b)->index == (*a)->index - 1)
			pa(a, b, 1);
		else if (lstlast(*a)->index == (*a)->index - 1)
			rra(a, 1);
		else if (*b && (lstlast(*a)->index == size - 1
				|| (*b)->index > lstlast(*a)->index))
		{
			pa(a, b, 1);
			if (srch_idx(*b, (*a)->index - 1) < lstsize(b) / 2)
				rr(a, b, 1);
			else
				ra(a, 1);
		}
		else if (lstsize(b) > 1)
		{
			if (srch_idx(*b, (*a)->index - 1) < lstsize(b) / 2)
				rb(b, 1);
			else
				rrb(b, 1);
		}
	}
}

void	five_hundred(t_lst **a, t_lst **b)
{
	int		size;
	int		i;

	i = 40;
	size = lstsize(a);
	initializ_one(*a);
	initialize_index(a, size - 1);
	while (*a)
	{
		fdividing_stack_a(a, b, size / 2 - i, size / 2 + i);
		i += 40;
	}
	push_max(a, b);
	fonction_help(a, b, size);
}
