/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 10:37:22 by molasz-a          #+#    #+#             */
/*   Updated: 2024/02/24 11:15:37 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>

typedef struct s_list
{
	int				x;
	int				y;
	int				z;
	int				color;
	struct s_list	*next;
}		t_list;

int		ft_atoi_base(char *str, char *base);

t_list	*ft_lstnew(int x, int y, int z);
void	ft_lstadd_back(t_list **lst, t_list *n);
void	ft_lstclear(t_list **lst);

#endif
