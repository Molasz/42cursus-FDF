/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:27:12 by molasz-a          #+#    #+#             */
/*   Updated: 2024/02/29 20:30:17 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	on_error(t_mlx *mlx)
{
	free_coords(mlx);
	return (1);
}

void	free_coords(t_mlx *mlx)
{
	int	i;

	i = 0;
	while (i < mlx->max_y)
		free(mlx->coords[i++]);
	free(mlx->coords);
}

static int	on_close(t_mlx *mlx)
{
	if (mlx->img)
		mlx_destroy_image(mlx->mlx, mlx->img->img);
	free_coords(mlx);
	mlx_destroy_window(mlx->mlx, mlx->win);
	exit(0);
	return (0);
}

static int	on_key(int n, t_mlx *mlx)
{
	printf("%d\n", n);
	if (n == 53)
		on_close(mlx);
	if (n == 49)
		new_image(mlx, mlx->img);
	return (0);
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;
	t_img	img;

	if (argc == 2)
	{
		if (parser_limits(argv[1], &mlx) || parser(argv[1], &mlx))
			return (1);
		mlx.mlx = mlx_init();
		if (!mlx.mlx)
			on_error(&mlx);
		mlx.win = mlx_new_window(mlx.mlx, mlx.width, mlx.height, "FDF");
		if (!mlx.win || new_image(&mlx, &img))
			on_error(&mlx);
		mlx_hook(mlx.win, ON_KEYUP, 0, on_key, &mlx);
		mlx_hook(mlx.win, ON_DESTROY, 0, on_close, &mlx);
		mlx_loop(mlx.mlx);
	}
	return (0);
}
