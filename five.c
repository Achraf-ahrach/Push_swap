/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahrach <aahrach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:10:23 by aahrach           #+#    #+#             */
/*   Updated: 2023/02/05 14:38:08 by aahrach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int acses(t_lst *stack_a)
{
	int	min = 0;

	if(stack_a)
	{
		min = stack_a->content;
		stack_a = stack_a->next;
	}
	while (stack_a)
	{
		
		if (min > stack_a->content)
			return (-1);
		min = stack_a->content;
		stack_a = stack_a->next;
	}
	return (0);
}

int	index_min(t_lst *stack_a, int min)
{
	int	i;

	i = 0;
	while (stack_a)
	{
		if (stack_a->content == min)
			return (i);
		stack_a = stack_a->next;
		i++;
	}
	return (i);
}

int	min_five(t_lst *stack_a, int *min)
{
	t_lst	*a;
	int		index;

	a = stack_a;
	*min = a->content;
	a = a->next;
	while (a)
	{
		if (*min > a->content)
			*min = a->content;
		a = a->next;
	}
	index = index_min(stack_a, *min);
	return (index);
}

void	five(t_lst **stack_a, t_lst **b)
{
	int		index;
	int		min;

	while (lstsize(stack_a) > 3)
	{
		index = min_five(*stack_a, &min);
		if (index >= (5 / 2))
		{
			while ((*stack_a)->content != min)
				rra(stack_a);
			pb(b, stack_a);
		}
		else if (index < (5 / 2))
		{
			while ((*stack_a)->content != min)
				ra(stack_a);
			pb(b, stack_a);
		}
	}
	three(stack_a);
	while (*b)
		pa(stack_a, b);
}