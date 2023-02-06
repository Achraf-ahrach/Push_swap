/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahrach <aahrach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:37:52 by aahrach           #+#    #+#             */
/*   Updated: 2023/02/06 23:31:43 by aahrach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	lstadd_back(t_lst **lst, t_lst *new)
{
	t_lst	*p;

	if (!new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	p = *lst;
	while (p->next != NULL)
		p = p->next;
	p->next = new;
	new->next = NULL;
}

t_lst	*lstnew(int content)
{
	t_lst	*p;

	p = malloc(sizeof(t_lst));
	if (!p)
		return (NULL);
	p->content = content;
	p->next = NULL;
	return (p);
}

void	lstadd_front(t_lst **lst, t_lst *new)
{
	if (!lst)
		*lst = new;
	new->next = (*lst);
	(*lst) = new;
}

int	lstsize(t_lst **lst)
{
	int		len;
	t_lst	*tmp;

	len = 0;
	tmp = *lst;
	while (tmp)
	{
		tmp = tmp->next;
		len++;
	}
	return (len);
}

t_lst	*lstlast(t_lst *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
