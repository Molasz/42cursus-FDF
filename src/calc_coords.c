/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_coords.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 19:33:55 by molasz-a          #+#    #+#             */
/*   Updated: 2024/02/28 22:19:26 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static float	set_win_size(t_mlx *mlx)
{
	t_list	*tmp;
	float	size;

	tmp = ft_lstlast(mlx->coords);
	if (tmp->x > tmp->y)
	{
		mlx->x_size = SIZE;
		size = SIZE / 2 / (tmp->x + 0.1);
		mlx->y_size = size * (tmp->y + 1) + (SIZE / 2);
	}
	else
	{
		mlx->y_size = SIZE;
		size = SIZE / 2 / (tmp->y + 0.1);
		mlx->x_size = size * (tmp->x + 1) + (SIZE / 2);
	}
	return (size);
}

void	calc_coords(t_mlx *mlx)
{
	t_list	*tmp;
	float	size;
	int		space;

	size = set_win_size(mlx);
	tmp = mlx->coords;
	space = SIZE / 4;
	while (tmp)
	{
		tmp->x = tmp->x * size + space;
		tmp->y = tmp->y * size + space;
		tmp = tmp->next;
	}
}
