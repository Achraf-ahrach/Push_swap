/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahrach <aahrach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 17:47:18 by aahrach           #+#    #+#             */
/*   Updated: 2023/02/05 18:02:04 by aahrach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error_lst(t_lst *p)
{
	t_lst	*s;

	write (2, "Error\n", 6);
	if (!p)
		exit (5);
	while (p)
	{
		s = p;
		p = p->next;
		free(s);
	}
	exit (1);
}

int	check(char **av)
{
	int i;
	int j;

	i = 1;
	while (av[i])
	{
		j = 0;
		if ((av[i][j] == '-' && av[i][j + 1]) || (av[i][j] == '+' && av[i][j + 1]))
			j++;
		while (av[i][j])
		{
			if ((av[i][j] == '+' && av[i][j - 1] == ' ' && av[i][j + 1] != ' ') ||
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
			ft_error_lst(p);
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

int	repeat_of_numbers(t_lst *p)
{
	t_lst	*s;

	if (!p)
		ft_error_lst(p);
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

int main(int ac, char **av)
{
	t_lst	*stack_a;

	if ( ac < 2)
		exit (0);
	if (check(av) == -1)
	{
		write (2, "Error\n", 6);
		exit (1);
	}
	stack_a = hoop(av + 1);
	if (repeat_of_numbers(stack_a) == -1 || lstsize(&stack_a) == 0)
		ft_error_lst(stack_a);
	push_swap(&stack_a);
}