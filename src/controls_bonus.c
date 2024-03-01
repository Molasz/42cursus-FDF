/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:59:39 by molasz-a          #+#    #+#             */
/*   Updated: 2024/03/01 13:01:07 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	on_key_bonus(int n, t_mlx *mlx)
{
	if (n == 123)
		mlx->x_shift -= 10;
	else if (n == 124)
		mlx->x_shift += 10;
	else if (n == 125)
		mlx->y_shift += 10;
	else if (n == 126)
		mlx->y_shift -= 10;
	else if (n == 18 && mlx->angle != 360)
		mlx->angle += 10;
	else if (n == 19 && mlx->angle != 0)
		mlx->angle -= 10;
	else
		printf("%d\n", n);
	new_image(mlx, mlx->img);
}
