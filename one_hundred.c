/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_hundred.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahrach <aahrach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 19:06:48 by aahrach           #+#    #+#             */
/*   Updated: 2023/02/05 14:11:52 by aahrach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initializ_one(t_lst *stack_a)
{
	while (stack_a)
	{
		stack_a->index = -1;
		stack_a = stack_a->next;
	}
}

void	rank(int min, t_lst *stack_a)
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

void	initialize_index(t_lst **stack_a, int max_index)
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
		rank(min, *stack_a);
		max_index--;
	}
}

void	Dividing_stack_a(t_lst **stack_a, t_lst **stack_b, int start, int end)
{
	int	i;

	i = start;
	while (i < end)
	{
		if ((*stack_a)->index >= start && (*stack_a)->index < end)
		{
			if (lstsize(stack_b) && (*stack_a)->index <= start + (end - start) / 2)
			{
				pb(stack_b, stack_a);
				if ((*stack_a) && (*stack_a)->index > end)
					rr(stack_a, stack_b);
				else
					rb(stack_b);
			}
			else
				pb(stack_b, stack_a);
			i++;
		}
		else
			ra(stack_a);
	}
}

int	search_index(t_lst *stack_b, int index)
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

void	one_hundred(t_lst **stack_a, t_lst **stack_b)
{
	int		size;
	int		i;

	i = 0;
	size = lstsize(stack_a); 
	initializ_one(*stack_a);
	initialize_index(stack_a, size - 1);
	while (i < 5)
	{
		Dividing_stack_a(stack_a, stack_b, (i * size / 5), ((i + 1) * size) / 5);
		i++;
	}
	while (*stack_b)
	{
		if ((*stack_b)->index == size - 1)
		{
			pa(stack_a, stack_b);
			size--;
		}
		else
		{
			if (search_index((*stack_b), size - 1) < size / 2)
				rb(stack_b);
			else
				rrb(stack_b);
		}
	}
}
