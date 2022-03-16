/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_functions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymourchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 17:31:46 by ymourchi          #+#    #+#             */
/*   Updated: 2022/02/04 17:31:49 by ymourchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
