/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahrach <aahrach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 09:05:26 by aahrach           #+#    #+#             */
/*   Updated: 2023/02/05 13:47:48 by aahrach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_lst **stack_a)
{
	t_lst	*b;

	b = 0;
	if (lstsize(stack_a) == 1 || acses(*stack_a) == 0)
		exit (0);
	else if (lstsize(stack_a) == 2)
		sa(stack_a);
	else if (lstsize(stack_a) == 3)
		three(stack_a);
	else if (lstsize(stack_a) == 5 || lstsize(stack_a) == 4)
		five(stack_a, &b);
	else if (lstsize(stack_a) <= 100)
		one_hundred(stack_a, &b);
	else
		five_hundred(stack_a, &b);
}