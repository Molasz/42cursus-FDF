/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:27:12 by molasz-a          #+#    #+#             */
/*   Updated: 2024/03/01 17:30:26 by molasz-a         ###   ########.fr       */
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
		controls(&mlx);
		mlx_loop(mlx.mlx);
	}
	return (0);
}
