/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_events.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 23:44:41 by molasz-a          #+#    #+#             */
/*   Updated: 2024/03/01 23:50:14 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	on_close(t_mlx *mlx)
{
	if (mlx->img)
		mlx_destroy_image(mlx->mlx, mlx->img->img);
	free_coords(mlx);
	mlx_destroy_window(mlx->mlx, mlx->win);
	exit(0);
	return (0);
}

#ifndef BONUS

int	on_key(int n, t_mlx *mlx)
{
	if (n == ESC)
		on_close(mlx);
	return (0);
}

#else

int	on_key(int n, t_mlx *mlx)
{
	if (n == ESC)
		on_close(mlx);
	else
		on_key_bonus(n, mlx);
	return (0);
}

int	on_mouse(int n, int x, int y, t_mlx *mlx)
{
	(void) (x + y);
	on_mouse_bonus(n, mlx);
	return (0);
}

#endif
