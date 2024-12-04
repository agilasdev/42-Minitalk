#include "minitalk.h"

void	client_sig_handler(int signum)
{
	(void)signum;
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

int	main(int argc, char *argv[])
{
	if (argc == 3)
		client(argv[1], argv[2]);
	return (0);
}
