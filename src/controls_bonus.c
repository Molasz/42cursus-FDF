/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:59:39 by molasz-a          #+#    #+#             */
/*   Updated: 2024/03/01 15:39:08 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	on_key_bonus(int n, t_mlx *mlx)
{
	if (n == LEFT)
		mlx->x_shift -= 10;
	else if (n == RIGHT)
		mlx->x_shift += 10;
	else if (n == DOWN)
		mlx->y_shift += 10;
	else if (n == UP)
		mlx->y_shift -= 10;
	else if (n == 18 && mlx->angle != 360)
		mlx->angle += 10;
	else if (n == 19 && mlx->angle != 0)
		mlx->angle -= 10;
	else
		printf("%d\n", n);
	new_image(mlx, mlx->img);
}

int	on_mouse(int button, int x, int y, t_mlx *mlx)
{
	printf("%d %d %d %p\n", button, x, y, mlx);
	return (0);
}
