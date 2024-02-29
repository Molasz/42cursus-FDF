/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_coords.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 19:33:55 by molasz-a          #+#    #+#             */
/*   Updated: 2024/02/29 17:19:06 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	calc_coords(t_mlx *mlx)
{
	t_list	*lst;
	float	angle;

	angle = mlx->angle / 180.0;
	lst = mlx->coords;
	while (lst)
	{
		lst->x *= mlx->scale;
		lst->y *= mlx->scale;
		lst->z *= mlx->zscale;
		lst->x = (lst->x - lst->y) * cos(angle);
		lst->y = (lst->x + lst->y) * sin(angle) - lst->z;
		lst->x += mlx->x_shift;
		lst->y += mlx->y_shift;
		lst = lst->next;
	}
}
