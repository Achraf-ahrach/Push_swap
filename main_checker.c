/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahrach <aahrach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 18:50:05 by aahrach           #+#    #+#             */
/*   Updated: 2023/02/07 00:19:46 by aahrach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	repeat_of_numbers(t_lst *p)
{
	t_lst	*s;

	if (!p)
		ft_error_lst(p, 0);
	s = p->next;
	while (p)
	{
		s = p->next;
		while (s)
		{
			if (p->content == s->content)
				return (-1);
			s = s->next;
		}
		p = p->next;
	}
	return (0);
}

int	check(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		if ((av[i][j] == '-' && av[i][j + 1])
			|| (av[i][j] == '+' && av[i][j + 1]))
			j++;
		while (av[i][j])
		{
			if ((av[i][j] == '+' && av[i][j - 1] == ' ' &&
				av[i][j + 1] != ' ') ||
				(av[i][j] == '-' && av[i][j - 1] == ' ' && av[i][j + 1] != ' '))
				j++;
			else if ((av[i][j] == ' ') || (av[i][j] >= '0' && av[i][j] <= '9'))
				j++;
			else
				return (-1);
		}
		i++;
	}
	return (0);
}

t_lst	*hoop(char **av)
{
	int		i;
	int		j;
	char	**s;
	t_lst	*p;

	i = 0;
	p = NULL;
	while (av[i])
	{
		s = ft_split(av[i], ' ');
		if (!s)
			ft_error_lst(p, 0);
		j = 0;
		while (s[j])
		{
			lstadd_back(&p, lstnew(ft_atoi(s[j], p)));
			free(s[j]);
			j++;
		}
		free(s);
		i++;
	}
	return (p);
}

int	acses(t_lst *stack_a)
{
	int	min;

	if (stack_a)
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

int	main(int ac, char **av)
{
	t_lst	*stack_a;

	if (ac < 2)
		exit (0);
	if (check(av) == -1)
	{
		write (2, "Error\n", 6);
		exit (1);
	}
	stack_a = hoop(av + 1);
	if (repeat_of_numbers(stack_a) == -1)
		ft_error_lst(stack_a, 2);
	else if (lstsize(&stack_a) == 0)
		ft_error_lst(stack_a, 2);
	checker(&stack_a);
}
