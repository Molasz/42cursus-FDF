/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 10:37:22 by molasz-a          #+#    #+#             */
/*   Updated: 2024/02/25 19:30:25 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "get_next_line.h"
# include <stdlib.h>
# include <stdio.h>

typedef struct s_color
{
	int	t;
	int	r;
	int	g;
	int	b;
	int	dt;
	int	dr;
	int	dg;
	int	db;
}			t_color;

typedef struct s_list
{
	int				x;
	int				y;
	int				z;
	t_color			color;
	struct s_list	*next;
}		t_list;

int		ft_atoi_base(char *str, char *base);

t_list	*ft_lstnew(int x, int y, int z);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *n);
void	ft_lstclear(t_list **lst);

#endif
