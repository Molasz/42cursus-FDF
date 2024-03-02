/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:27:12 by molasz-a          #+#    #+#             */
/*   Updated: 2024/03/02 12:17:01 by molasz-a         ###   ########.fr       */
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
	while (i < mlx->y_max)
		free(mlx->coords[i++]);
	free(mlx->coords);
}

static void	set_color(t_mlx *mlx, int x, int y)
{
	mlx->coords[y][x].r = 255;
	mlx->coords[y][x].g = 255;
	mlx->coords[y][x].b = 255;
	if (mlx->coords[y][x].z >= 0)
	{
		mlx->coords[y][x].r = 255.0 / mlx->z_max * mlx->coords[y][x].z;
		mlx->coords[y][x].b = 255.0 / mlx->z_max * mlx->coords[y][x].z;
	}
	else if (mlx->coords[y][x].z < 0)
	{
		mlx->coords[y][x].r = 255.0 / mlx->z_max * -mlx->coords[y][x].z;
		mlx->coords[y][x].g = 255.0 / mlx->z_max * -mlx->coords[y][x].z;
	}
}

static void	update_colors(t_mlx *mlx)
{
	int	x;
	int	y;

	y = 0;
	while (y < mlx->y_max)
	{
		x = 0;
		while (x < mlx->x_max)
		{
			if (!mlx->coords[y][x].r && !mlx->coords[y][x].g
					&& !mlx->coords[y][x].b)
				set_color(mlx, x, y);
			x++;
		}
		y++;
	}
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;
	t_img	img;

	if (argc == 2)
	{
		if (parser_limits(argv[1], &mlx) || parser(argv[1], &mlx))
			return (1);
		update_colors(&mlx);
		mlx.mlx = mlx_init();
		if (!mlx.mlx)
			on_error(&mlx);
		mlx.win = mlx_new_window(mlx.mlx, mlx.width, mlx.height, "FDF");
		if (!mlx.win || new_image(&mlx, &img))
			on_error(&mlx);
		controls(&mlx);
		mlx_loop(mlx.mlx);
	}
	return (0);
}
