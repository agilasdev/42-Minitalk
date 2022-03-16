/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_fn.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymourchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 18:39:23 by ymourchi          #+#    #+#             */
/*   Updated: 2022/02/17 18:39:25 by ymourchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	c;

	c = 0;
	i = 0;
	while (str[i])
	{
		c = (c * 10) + (str[i] - 48);
		i++;
	}
	return (c);
}

void	ft_putnbr(int n)
{
	int	num;

	if (n < 10)
	{
		num = n + 48;
		write(1, &num, 1);
	}
	else
	{
		ft_putnbr(n / 10);
		num = (n % 10) + 48;
		write(1, &num, 1);
	}
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	send_bits(char l, int pid)
{
	int	i;
	int	j;

	i = 0;
	while (i < 8)
	{
		j = l >> i & 1;
		if (j)
			kill(pid, SIGUSR1);
		if (!j)
			kill(pid, SIGUSR2);
		i++;
		usleep(200);
	}
}
