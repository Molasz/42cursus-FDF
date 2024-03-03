/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 12:43:30 by molasz-a          #+#    #+#             */
/*   Updated: 2024/03/03 12:49:06 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	write_white(t_mlx *mlx, int x, int y, char *str)
{
	mlx_string_put(mlx->mlx, mlx->win, x, y, 0x50ffffff, str);
}

void	write_var(t_mlx *mlx, int x, int y, char *str)
{
	mlx_string_put(mlx->mlx, mlx->win, x, y, 0x50fcba03, str);
	free(str);
}

void	fill_menu(t_mlx *mlx)
{
	char	*dst;
	int		x;
	int		y;

	y = 0;
	while (y < mlx->height)
	{
		x = 0;
		while (x < MENU_SIZE)
		{
			dst = mlx->menu->addr
				+ (y * mlx->menu->line_len + x * (mlx->menu->bpp / 8));
			*(unsigned int *)dst = 0x504d4d4d;
			x++;
		}
		y++;
	}
}
