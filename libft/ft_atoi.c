/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahrach <aahrach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:25:32 by aahrach           #+#    #+#             */
/*   Updated: 2023/01/31 19:06:21 by aahrach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_atoi(char *str, t_lst *p)
{
	int		x;
	int		i;
	long	nbr;

	i = 0;
	nbr = 0;
	x = 1;
	if (str[i] == '-')
	{
		x = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = (nbr * 10) + (str[i] - 48);
		i++;
	}
	if (nbr * x > 2147483647 || nbr * x < -2147483648)
	{
		write (1, "max de int !", 12);
		ft_error_lst(p);
	}
	return (nbr * x);
}