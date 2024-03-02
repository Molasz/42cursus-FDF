/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 15:42:23 by molasz-a          #+#    #+#             */
/*   Updated: 2024/03/03 00:38:55 by molasz-a         ###   ########.fr       */
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

static void	write_white(t_mlx *mlx, int x, int y, char *str)
{
	mlx_string_put(mlx->mlx, mlx->win, x, y, 0x50ffffff, str);
}

static void	write_var(t_mlx *mlx, int x, int y, char *str)
{
	mlx_string_put(mlx->mlx, mlx->win, x, y, 0x50fcba03, str);
}

static void	write_menu(t_mlx *mlx)
{
	write_white(mlx, CHEAD_X, CHEAD_Y, "### CONTROLS ###");
	write_white(mlx, C_X, C_Y, "[Arrows] Move model");
	write_white(mlx, C_X, C_Y + SPACE, "[Mouse wheel] Zoom in / out");
	write_white(mlx, C_X, C_Y + SPACE * 2, "[W - S] Rotate Y angle");
	write_white(mlx, C_X, C_Y + SPACE * 3, "[A - D] Rotate X angle");
	write_white(mlx, C_X, C_Y + SPACE * 4, "[TAB] Alternate projection");
	write_white(mlx, IHEAD_X, IHEAD_Y, "### MAP INFO ###");
	write_white(mlx, I_X, I_Y, "Win width:");
	write_white(mlx, I_X, I_Y + SPACE, "Win height:");
	write_white(mlx, I_X, I_Y + SPACE * 2, "Max X:");
	write_white(mlx, I_X, I_Y + SPACE * 3, "Max Y:");
	write_white(mlx, I_X, I_Y + SPACE * 4, "Max Z:");
	write_white(mlx, VHEAD_X, VHEAD_Y, "### VARIABLES ###");
	write_white(mlx, V_X, V_Y, "Shift X:");
	write_white(mlx, V_X, V_Y + SPACE, "Shift Y:");
	write_white(mlx, V_X, V_Y + SPACE * 2, "Angle X:");
	write_white(mlx, V_X, V_Y + SPACE * 3, "Angle Y:");
	write_white(mlx, V_X, V_Y + SPACE * 4, "Scale XY:");
	write_white(mlx, V_X, V_Y + SPACE * 5, "Scale Z:");
	write_white(mlx, V_X, V_Y + SPACE * 6, "Projection:");
}

static void	write_vars(t_mlx *mlx)
{
	write_var(mlx, 20, 500, "HI");
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
	write_vars(mlx);
	return (0);
}
