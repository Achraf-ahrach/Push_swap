/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_hundred.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahrach <aahrach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 19:08:03 by aahrach           #+#    #+#             */
/*   Updated: 2023/02/06 12:56:01 by aahrach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	finitializ_one(t_lst *stack_a)
{
	while (stack_a)
	{
		stack_a->index = -1;
		stack_a = stack_a->next;
	}
}

void	frank(int min, t_lst *stack_a)
{
	static int i;

	while (stack_a)
	{
		if (stack_a->content == min)
		{
			stack_a->index = i;
			i++;
			break ;
		}
		stack_a = stack_a->next;
	}
}

void	finitialize_index(t_lst **stack_a, int max_index)
{
	t_lst	*copy;
	int		min;

	while (max_index >= 0)
	{
		copy = *stack_a;
		while (copy)
		{
			if (copy->index == -1)
			{
				min = copy->content;
				break ;
			}
			copy = copy->next;
		}
		copy = *stack_a;
		while (copy)
		{
			if (min > copy->content && copy->index == -1)
				min = copy->content;
			copy = copy->next;
		}
		frank(min, *stack_a);
		max_index--;
	}
}
int is_there_more(t_lst *list, int start, int end)
{
	while(list)
	{
		if(list->index >= start && list->index <= end)
			return(1);
		list = list->next;
	}
	return(0);
}

void	fDividing_stack_a(t_lst **stack_a, t_lst **stack_b, int start, int end)
{
	while (is_there_more(*stack_a, start, end))
	{
		if ((*stack_a)->index >= start && (*stack_a)->index <= end)
		{
			if (lstsize(stack_b) && (*stack_a)->index <= start + (end - start) / 2)
			{
				pb(stack_b, stack_a);
				if (*stack_a && ((*stack_a)->index > end || (*stack_a)->index < start))
					rr(stack_a, stack_b);
				else
					rb(stack_b);
			}
			else
				pb(stack_b, stack_a);
		}
		else
			ra(stack_a);
	}
}

int	fsearch_index(t_lst *stack_b, int index)
{
	int i;

	i = 0;
	while (stack_b)
	{
		if (stack_b->index == index)
			return (i);
		i++;
		stack_b = 	stack_b->next;
	}
	return (i);
}

t_lst *max_ele(t_lst *t)
{
	t_lst *max;

	max = t;
	while(t)
	{
		if(t->content > max->content)
			max = t;
		t = t->next;
	}
	return(max);
}

void push_max(t_lst **stack_a,t_lst **stack_b)
{
	while (*stack_b)
	{
		if (*stack_b == max_ele(*stack_b))
		{
			pa(stack_a, stack_b);
			return;
		}
		else
			rb(stack_b);
	}
}

void	five_hundred(t_lst **stack_a, t_lst **stack_b)
{
	int		size;
	int		i = 40;
	size = lstsize(stack_a); 
	finitializ_one(*stack_a);
	finitialize_index(stack_a, size - 1);
	while (*stack_a)
	{
		fDividing_stack_a(stack_a, stack_b, size / 2 - i, size / 2 + i);
		i += 40;
	}
	push_max(stack_a, stack_b);
	while (*stack_b || acses(*stack_a) == -1)
	{
		if (*stack_b && (*stack_b)->index ==  (*stack_a)->index - 1)
			pa(stack_a, stack_b);
		else if(lstlast(*stack_a)->index == (*stack_a)->index - 1)
			rra(stack_a);
		else if(*stack_b && (lstlast(*stack_a) == max_ele(*stack_a) || (*stack_b)->index > lstlast(*stack_a)->index))
		{
			pa(stack_a, stack_b);
			if(fsearch_index(*stack_b, (*stack_a)->index - 1) < lstsize(stack_b) / 2)
				rr(stack_a, stack_b);
			else
				ra(stack_a);
		}
		else if(lstsize(stack_b) > 1)
		{
			if (fsearch_index(*stack_b, (*stack_a)->index - 1) < lstsize(stack_b) / 2)
				rb(stack_b);
			else
				rrb(stack_b);
		}
	}
}