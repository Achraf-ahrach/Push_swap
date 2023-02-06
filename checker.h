/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahrach <aahrach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 15:58:28 by aahrach           #+#    #+#             */
/*   Updated: 2023/02/07 00:07:31 by aahrach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "push_swap.h"

t_lst	*lstnew(int content);
void	checker(t_lst **stack_a);
int		ft_strlen(char *s);
int		check_line(char *str);
char	*ft_substr(char *s, int start, int len, int x);
t_lst	*lstlast(t_lst *lst);
int		ft_atoi(char *str, t_lst *p);
char	**ft_split(char *s, char c);
char	*fft_substr(char *s, int start, int len, int x);
void	lstadd_back(t_lst **lst, t_lst *new);
void	lstadd_front(t_lst **list, t_lst *new);
int		lstsize(t_lst **lst);
char	*get_next_line(int fd);
char	*ft_free(char *buf, char **p);
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
int		check_line(char *str);
void	ss(t_lst *stack_a, t_lst *stack_b);

#endif