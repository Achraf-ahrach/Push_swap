/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahrach <aahrach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 15:52:38 by aahrach           #+#    #+#             */
/*   Updated: 2023/02/07 15:40:32 by aahrach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rrr(t_lst **stack_a, t_lst **stack_b)
{
	t_lst	*p;
	t_lst	*new;

	if (!(*stack_a) || !(*stack_b) || !(*stack_a)->next || !(*stack_b)->next)
		return ;
	p = (*stack_a);
	while (p->next->next)
		p = p->next;
	new = p->next;
	p->next = NULL;
	lstadd_front(stack_a, new);
	p = (*stack_b);
	while (p->next->next)
		p = p->next;
	new = p->next;
	p->next = NULL;
	lstadd_front(stack_b, new);
}

// void	ft_error_lst(t_lst *p)
// {
// 	t_lst	*s;

// 	write (2, "Error\n", 6);
// 	if (!p)
// 		exit (5);
// 	while (p)
// 	{
// 		s = p;
// 		p = p->next;
// 		free(s);
// 	}
// 	exit (1);
// }

void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit (1);
}

void	help(char *s, t_lst **stack_a, t_lst **stack_b)
{
	if (s[0] == 'p' && s[1] == 'a' && s[2] == '\n')
		pa(stack_a, stack_b, 0);
	else if (s[0] == 'p' && s[1] == 'b' && s[2] == '\n')
		pb(stack_b, stack_a, 0);
	else if (s[0] == 'r' && s[1] == 'a' && s[2] == '\n')
		ra(stack_a, 0);
	else if (s[0] == 'r' && s[1] == 'b' && s[2] == '\n')
		rb(stack_b, 0);
	else if (s[0] == 'r' && s[1] == 'r' && s[2] == '\n')
		rr(stack_a, stack_b, 0);
	else if (s[2] == '\n')
		error_exit();
	else if (s[0] == 'r' && s[1] == 'r' && s[2] == 'a' && s[3] == '\n')
		rra(stack_a, 0);
	else if (s[0] == 'r' && s[1] == 'r' && s[2] == 'b' && s[3] == '\n')
		rrb(stack_b, 0);
	else if (s[0] == 'r' && s[1] == 'r' && s[2] == 'r' && s[3] == '\n')
		rrr(stack_a, stack_b);
	else
		error_exit();
}

void	checker(t_lst **stack_a)
{
	t_lst	*stack_b;
	char	*str;

	stack_b = NULL;
	str = "";
	while (str)
	{
		str = get_next_line(0);
		if (!str || !str[0])
			break ;
		if (str[0] == '\n' || str[1] == '\n')
			error_exit();
		if (str[0] == 's' && str[1] == 'a' && str[2] == '\n')
			sa(stack_a, 0);
		else if (str[0] == 's' && str[1] == 'b' && str[2] == '\n')
			sb(&stack_b, 0);
		else if (str[0] == 's' && str[1] == 's' && str[2] == '\n')
			ss(*stack_a, stack_b);
		else
			help(str, stack_a, &stack_b);
	}
	if (acses(*stack_a) == 0)
		write (2, "OK\n", 3);
	else
		write (2, "KO\n", 3);
}
