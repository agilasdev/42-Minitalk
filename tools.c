#include "minitalk.h"

t_list	*ft_lstnew(void)
{
	t_list	*msg;

	msg = (t_list *) malloc(sizeof(t_list));
	if (msg)
	{
		msg -> ch = 0;
		msg -> next = NULL;
		return (msg);
	}
	else
		return (NULL);
}

t_list	*ft_lstlast(t_list *lst)
{
	while (lst)
	{
		if (!lst -> next)
			break ;
		lst = lst -> next;
	}
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*blast;

	if (!(*lst))
		*lst = new;
	else
	{
		blast = ft_lstlast(*lst);
		blast -> next = new;
	}
}

void	ft_lstclear(t_list **lst)
{
	if (*lst)
	{
		if (!((*lst)-> next))
			ft_lstdelone((*lst));
		else
		{
			ft_lstclear(&(*lst)->next);
			ft_lstdelone(*lst);
		}
	}
}

void	ft_lstdelone(t_list *lst)
{
	if (lst)
		free(lst);
}

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
