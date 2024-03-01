/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 22:15:54 by molasz-a          #+#    #+#             */
/*   Updated: 2024/03/01 23:49:08 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

#ifndef BONUS

# ifndef LINUX

void	controls(t_mlx *mlx)
{
	mlx_hook(mlx->win, ON_DESTROY, 0, on_close, mlx);
	mlx_hook(mlx->win, ON_KEYDOWN, 0, on_key, mlx);
}

# else

void	controls(t_mlx *mlx)
{
	mlx_hook(mlx->win, ON_DESTROY, 0, on_close, mlx);
	mlx_key_hook(mlx->win, on_key, mlx);
}

# endif

#else

# ifndef LINUX

void	controls(t_mlx *mlx)
{
	mlx_hook(mlx->win, ON_DESTROY, 0, on_close, mlx);
	mlx_hook(mlx->win, ON_KEYDOWN, 0, on_key, mlx);
	mlx_mouse_hook(mlx->win, on_mouse, mlx);
}

# else

void	controls(t_mlx *mlx)
{
	mlx_hook(mlx->win, ON_DESTROY, 0, on_close, mlx);
	mlx_key_hook(mlx->win, on_key, mlx);
	mlx_mouse_hook(mlx->win, on_mouse, mlx);
}

# endif

#endif
