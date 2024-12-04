#include "minitalk.h"

t_list	*g_message;

void	sig_handler(int signum)
{
	t_list		*tmp;
	static char	i = 1;
	static char	j = 0;

	printf("%d", j);
	if (j == 8)
	{
		ft_lstadd_back(&g_message, ft_lstnew());
		i = 1;
		j = 0;
	}
	if (signum == 10)
	{
		tmp = ft_lstlast(g_message);
		tmp->ch = tmp->ch + i;
	}
	i = i * 2;
	j++;
}

void	print_msg(int signum, siginfo_t *siginfo, void *context)
{
	// void	*useless;
	t_list	*tmp;

	tmp = g_message;
	(void)context;
	if (signum)
	{
		while (tmp)
		{
			write(1, &(tmp->ch), 1);
			tmp = tmp -> next;
		}
		write(1, "\n", 1);
		ft_lstdelone(g_message);
		g_message = NULL;
		kill(siginfo->si_pid, SIGUSR1);
	}
}

int	main(void)
{
	struct sigaction	sa1;
	struct sigaction	sa2;

	sa1.sa_handler = &sig_handler;
	sa1.sa_flags = SA_RESTART;
	sa2.sa_sigaction = &print_msg;
	sa2.sa_flags = SA_SIGINFO;
	ft_putnbr(getpid());
	write(1, "\n", 1);
	ft_lstadd_back(&g_message, ft_lstnew());
	sigaction(SIGUSR1, &sa1, NULL);
	sigaction(SIGUSR2, &sa1, NULL);
	sigaction(1, &sa2, NULL);
	while (1)
		pause();
	return (0);
}
