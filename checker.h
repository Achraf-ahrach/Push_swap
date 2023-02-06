/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahrach <aahrach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 15:58:28 by aahrach           #+#    #+#             */
/*   Updated: 2023/02/06 16:43:30 by aahrach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_lst{
	int content;
	int	index;
	struct s_lst *next;
}	t_lst;

t_lst	*lstnew(int content);
size_t	ft_strlen(char *s);
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
char	*ft_strdup(char *s1);
int		check_line(char *str);
char	*ft_substr(char *str, int start, int len, int x);
size_t	ft_strlen(char *s);
#endif