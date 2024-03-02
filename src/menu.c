/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 15:42:23 by molasz-a          #+#    #+#             */
/*   Updated: 2024/03/02 16:45:54 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	fill_menu(t_mlx *mlx)
{
	char	*dst;
	int	x;
	int	y;

	y = 0;
	while (y < mlx->height)
	{
		x = 0;
		while (x < MENU_SIZE)
		{
			dst = mlx->menu->addr + (y * mlx->menu->line_len + x * (mlx->menu->bpp / 8));
			*(unsigned int *)dst = 0x504d4d4d;
			x++;
		}
		y++;
	}
}

static void	write_menu(t_mlx *mlx)
{
	mlx_string_put(mlx->mlx, mlx->win, 65, 5, 0x50ffffff, "### CONTROLS ###");
	mlx_string_put(mlx->mlx, mlx->win, 15, 30, 0x50ffffff, "[Arrows] Move model");
	mlx_string_put(mlx->mlx, mlx->win, 15, 50, 0x50ffffff, "[Mouse wheel] Zoom in / out");
	mlx_string_put(mlx->mlx, mlx->win, 15, 70, 0x50ffffff, "[W - S] Rotate Y angle");
	mlx_string_put(mlx->mlx, mlx->win, 15, 90, 0x50ffffff, "[A - D] Rotate X angle");
	mlx_string_put(mlx->mlx, mlx->win, 15, 110, 0x50ffffff, "[TAB] Alternate projection");
}

int	new_menu(t_mlx *mlx, t_img *menu)
{
	if (mlx->menu == menu)
		mlx_destroy_image(mlx->mlx, menu->img);
	menu->img = mlx_new_image(mlx->mlx, MENU_SIZE, mlx->height);
	if (!menu->img)
		return (1);
	menu->addr = mlx_get_data_addr(menu->img,
			&menu->bpp, &menu->line_len, &menu->endian);
	mlx->menu = menu;
	fill_menu(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, menu->img, 0, 0);
	write_menu(mlx);
	return (0);
}
