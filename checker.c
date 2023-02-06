/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahrach <aahrach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 15:52:38 by aahrach           #+#    #+#             */
/*   Updated: 2023/02/06 16:53:46 by aahrach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

//// opration >>>>>>

void	sa(t_lst **stack_a)
{
	int		swap;
	t_lst	*a;

	if (!(*stack_a) || !(*stack_a)->next)
		return ;
	a = *stack_a;
	swap = a->content;
	a->content = a->next->content;
	a->next->content = swap;
}

void	sb(t_lst **lst)
{
	int	swap;

	if (!(*lst) || !(*lst)->next)
		return ;
	swap = (*lst)->content;
	(*lst)->content = (*lst)->next->content;
	(*lst)->next->content = swap;
}

void	ss(t_lst *stack_a, t_lst *stack_b)
{
	int		swap;

	if (!stack_a || !stack_b || !stack_a->next || !stack_b->next)
		return ;
	swap = stack_a->content;
	stack_a->content = stack_a->next->content;
	stack_a->next->content = swap;
	swap = stack_b->content;
	stack_b->content = stack_b->next->content;
	stack_b->next->content = swap;
}

void	ra(t_lst **lst)
{
	t_lst	*p;

	if (!(*lst) || !(*lst)->next)
		return ;
	p = (*lst);
	(*lst) = (*lst)->next;
	p->next = NULL; 
	lstadd_back(lst, p);
}

void	rb(t_lst **lst)
{
	t_lst	*p;

	if (!(*lst) || !(*lst)->next)
		return ;
	p = (*lst);
	(*lst) = (*lst)->next;
	p->next = NULL;
	lstadd_back(lst, p);
}

void	rr(t_lst **a, t_lst **b)
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
}

void	rra(t_lst **lst)
{
	t_lst	*p;
	t_lst	*new;

	if (!(*lst) || !(*lst)->next)
		return ;
	p = (*lst);
	while (p->next->next)
		p = p->next;
	new = p->next;
	p->next = NULL;
	lstadd_front(lst, new);
}

void	rrb(t_lst **lst)
{
	t_lst	*p;
	t_lst	*new;

	if (!(*lst) || !(*lst)->next)
		return ;
	p = (*lst);
	while (p->next->next)
		p = p->next;
	new = p->next;
	p->next = NULL;
	lstadd_front(lst, new);
}

void	pa(t_lst **a, t_lst **b)
{
	t_lst *p;

	if (!b)
		return ;
	p = (*b);
	(*b) = (*b)->next;
	p->next = NULL;
	lstadd_front(a, p);
}

void	pb(t_lst **b, t_lst **a)
{
	t_lst *new;

	if (!a)
		return ;
	new = (*a);
	(*a) = (*a)->next;
	new->next = NULL;
	lstadd_front(b, new);
}

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

/////^^^^^^

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
		{
			write(2, "Error\n", 6);
			exit (1);
		}
		if (str[0] == 's' && str[1] == 'a' && str[2] == '\n')
			sa(stack_a);
		else if (str[0] == 's' && str[1] == 'b' && str[2] == '\n')
			sb(&stack_b);
		else if (str[0] == 's' && str[1] == 's' && str[2] == '\n')
			ss(*stack_a, stack_b);
		else if (str[0] == 'p' && str[1] == 'a' && str[2] == '\n')
			pa(stack_a, &stack_b);
		else if (str[0] == 'p' && str[1] == 'b' && str[2] == '\n')
			pb(&stack_b, stack_a);
		else if (str[0] == 'r' && str[1] == 'a' && str[2] == '\n')
			ra(stack_a);
		else if (str[0] == 'r' && str[1] == 'b' && str[2] == '\n')
			rb(&stack_b);
		else if (str[0] == 'r' && str[1] == 'r' && str[2] == '\n')
			rr(stack_a, &stack_b);
		else if (str[2] == '\n')
		{
			write(2, "Error\n", 6);
			exit (1);
		}
		else if (str[0] == 'r' && str[1] == 'r' && str[2] == 'a' && str[3] == '\n')
			rra(stack_a);
		else if (str[0] == 'r' && str[1] == 'r' && str[2] == 'b' && str[3] == '\n')
			rrb(&stack_b);
		else if (str[0] == 'r' && str[1] == 'r' && str[2] == 'r' && str[3] == '\n')
			rrr(stack_a, &stack_b);
		else
		{
			write(2, "Error\n", 6);
			exit (1);
		}
	}
	if (acses(*stack_a) == 0)
		write (2, "OK\n", 3);
	else
		write (2, "KO\n", 3);
}

int main(int ac, char **av)
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
	if (repeat_of_numbers(stack_a) == -1 || lstsize(&stack_a) == 0)
		ft_error_lst(stack_a);
	checker(&stack_a);
}
