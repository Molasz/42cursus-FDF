/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:59:39 by molasz-a          #+#    #+#             */
/*   Updated: 2024/03/03 12:39:59 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	on_angle_update(int n, t_mlx *mlx)
{
	if (n == W)
	{
		if ((int) mlx->y_angle == 2)
			mlx->y_angle = -2;
		mlx->y_angle += 0.1;
	}
	else if (n == S)
	{
		if ((int) mlx->y_angle == -2)
			mlx->y_angle = 2;
		mlx->y_angle -= 0.1;
	}
	else if (n == A)
	{
		if ((int) mlx->x_angle == 2)
			mlx->x_angle = -2;
		mlx->x_angle += 0.1;
	}
	else if (n == D)
	{
		if ((int) mlx->x_angle == -2)
			mlx->x_angle = 2;
		mlx->x_angle -= 0.1;
	}
}

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
	else if (n == TAB)
		mlx->projection = !mlx->projection;
	else if (n == W || n == A || n == S || n == D)
		on_angle_update(n, mlx);
	else
		return ;
	new_image(mlx, mlx->img);
	new_menu(mlx, mlx->menu);
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
	new_menu(mlx, mlx->menu);
}
