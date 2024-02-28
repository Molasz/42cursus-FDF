/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 10:36:52 by molasz-a          #+#    #+#             */
/*   Updated: 2024/02/28 21:55:47 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(int x, int y, int z)
{
	t_list	*elem;

	elem = malloc(sizeof (t_list));
	if (!elem)
		return (NULL);
	elem->x = x;
	elem->y = y;
	elem->z = z;
	elem->next = NULL;
	return (elem);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (lst)
	{
		while (lst->next)
			lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *n)
{
	t_list	*lstlast;

	if (lst)
	{
		if (*lst)
		{
			lstlast = ft_lstlast(*lst);
			lstlast->next = n;
		}
		else
			*lst = n;
	}
	else
		lst = &n;
}

void	ft_lstclear(t_list **lst)
{
	t_list	*tmp;

	if (lst)
	{
		while (*lst)
		{
			tmp = (*lst)->next;
			free(*lst);
			(*lst) = tmp;
		}
	}
}
