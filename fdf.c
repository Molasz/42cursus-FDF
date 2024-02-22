/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:27:12 by molasz-a          #+#    #+#             */
/*   Updated: 2024/02/22 15:18:34 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


int	on_close(t_mlx *mlx)
{
	if (mlx->img)
		mlx_destroy_image(mlx->mlx, mlx->img->img);
	mlx_destroy_window(mlx->mlx, mlx->win);
	exit(0);
	return (0);
}

int	on_key(int n, t_mlx *mlx)
{
	if (n == 53)
		on_close(mlx);
	return (0);
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;
	t_img	img;

	if (argc && argv)
	{
		mlx.mlx = mlx_init();
		mlx.win = mlx_new_window(mlx.mlx, WIDTH, HEIGHT, "FDF");
		new_image(&mlx, &img);
		mlx_hook(mlx.win, ON_KEYUP, 0, on_key, &mlx);
		mlx_hook(mlx.win, ON_DESTROY, 0, on_close, &mlx);
		mlx_loop(mlx.mlx);
	}
	return (0);
}
