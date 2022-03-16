/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymourchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 11:39:03 by ymourchi          #+#    #+#             */
/*   Updated: 2022/02/12 19:36:51 by ymourchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	client_sig_handler(int signum)
{
	int	sig;

	sig = signum;
	write(1, "The Server has recieved the message\n", 36);
}

void	client(char	*pid, char *str)
{
	int					s_pid;
	size_t				leng;
	size_t				i;
	struct sigaction	sa;

	i = 0;
	leng = ft_strlen(str);
	s_pid = ft_atoi(pid);
	sa.sa_handler = &client_sig_handler;
	sa.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &sa, NULL);
	while (i < leng)
	{
		send_bits(str[i], s_pid);
		i++;
	}
	kill(s_pid, 1);
	pause();
}
