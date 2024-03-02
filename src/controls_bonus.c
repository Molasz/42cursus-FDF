/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:59:39 by molasz-a          #+#    #+#             */
/*   Updated: 2024/03/02 14:27:15 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	on_key_bonus(int n, t_mlx *mlx)
{
	if (n == LEFT)
		mlx->x_shift += 10;
	else if (n == RIGHT)
		mlx->x_shift -= 10;
	else if (n == UP)
		mlx->y_shift += 10;
	else if (n == DOWN)
		mlx->y_shift -= 10;
	else if (n == W)
		mlx->y_angle += 0.1;
	else if (n == S)
		mlx->y_angle -= 0.1;
	else if (n == A)
		mlx->x_angle += 0.1;
	else if (n == D)
		mlx->x_angle -= 0.1;
	else if (n == ISOMETRIC)
		mlx->projection = 0;
	else if (n == PRESPETIVE)
		mlx->projection = 1;
	else
		return ;
	new_image(mlx, mlx->img);
}

void	on_mouse_bonus(int n, t_mlx *mlx)
{
	if (n == MOUSE_UP && mlx->xy_scale > 1)
		mlx->xy_scale--;
	else if (n == MOUSE_DOWN)
		mlx->xy_scale++;
	else
		return ;
	new_image(mlx, mlx->img);
}
