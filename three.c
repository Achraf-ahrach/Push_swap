/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahrach <aahrach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:41:09 by aahrach           #+#    #+#             */
/*   Updated: 2023/02/06 20:30:51 by aahrach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	min_max(t_lst	*stack_a, int *min, int *max)
{
	*min = stack_a->content;
	*max = stack_a->content;
	stack_a = stack_a->next;
	while (stack_a)
	{
		if (*min > stack_a->content)
			*min = stack_a->content;
		if (*max < stack_a->content)
			*max = stack_a->content;
		stack_a = stack_a->next;
	}
}

void	three(t_lst **a)
{
	int	min;
	int	max;

	min_max(*a, &min, &max);
	if ((*a)->content != min && (*a)->content != max)
	{
		(*a) = (*a)->next;
		if ((*a)->content == min)
			sa(a, 1);
		else
			rra(a, 1);
	}
	else if ((*a)->content == max)
	{
		(*a) = (*a)->next;
		if ((*a)->content == min)
			ra(a, 1);
		else
			rra(sa(a, 1), 1);
	}
	else if ((*a)->content == min && (*a)->next->content == max)
		ra(sa(a, 1), 1);
}
