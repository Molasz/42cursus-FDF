/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 22:15:54 by molasz-a          #+#    #+#             */
/*   Updated: 2024/03/01 15:46:21 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	on_close(t_mlx *mlx)
{
	if (mlx->img)
		mlx_destroy_image(mlx->mlx, mlx->img->img);
	free_coords(mlx);
	mlx_destroy_window(mlx->mlx, mlx->win);
	exit(0);
	return (0);
}

#ifndef BONUS

static int	on_key(int n, t_mlx *mlx)
{
	if (n == ESC)
		on_close(mlx);
	return (0);
}

#else

static int	on_key(int n, t_mlx *mlx)
{
	if (n == ESC)
		on_close(mlx);
	else
		on_key_bonus(n, mlx);
	return (0);
}

#endif

#ifdef BONUS

void	controls(t_mlx *mlx)
{
	mlx_hook(mlx->win, ON_DESTROY, 0, on_close, mlx);
	mlx_key_hook(mlx->win, on_key, mlx);
	mlx_mouse_hook(mlx->win, on_mouse, mlx);
}

#else

void	controls(t_mlx *mlx)
{
	mlx_hook(mlx->win, ON_DESTROY, 0, on_close, mlx);
	mlx_key_hook(mlx->win, on_key, mlx);
}

#endif
