/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymourchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 17:32:09 by ymourchi          #+#    #+#             */
/*   Updated: 2022/02/12 19:41:08 by ymourchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <signal.h>

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct t_list
{
	char			ch;
	struct t_list	*next;
}	t_list;

size_t				ft_strlen(const char *str);
void				send_bits(char l, int pid);
int					ft_atoi(const char *str);
void				ft_putnbr(int n);

t_list				*ft_lstnew(void);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst);
void				ft_lstclear(t_list **lst);

void				server(void);
void				client(char	*pid, char *str);

void				sig_handler(int signum);
void				print_msg(int signum, siginfo_t *siginfo, void *context);
void				client_sig_handler(int signum);
#endif
