/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 15:42:23 by molasz-a          #+#    #+#             */
/*   Updated: 2024/03/05 02:58:53 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

#ifndef BONUS

static void	write_menu(t_mlx *mlx)
{
	write_white(mlx, IHEAD_X, IHEAD_Y, "### MAP INFO ###");
	write_white(mlx, I_X, I_Y, "Win width:");
	write_white(mlx, I_X, I_Y + PADD, "Win height:");
	write_white(mlx, I_X, I_Y + PADD * 2, "Max X:");
	write_white(mlx, I_X, I_Y + PADD * 3, "Max Y:");
	write_white(mlx, I_X, I_Y + PADD * 4, "Max Z:");
}

static void	write_vars(t_mlx *mlx)
{
	write_var(mlx, I_X + PADD * 6, I_Y, ft_itoa(mlx->width));
	write_var(mlx, I_X + PADD * 6, I_Y + PADD, ft_itoa(mlx->height));
	write_var(mlx, I_X + PADD * 6, I_Y + PADD * 2, ft_itoa(mlx->x_max));
	write_var(mlx, I_X + PADD * 6, I_Y + PADD * 3, ft_itoa(mlx->y_max));
	write_var(mlx, I_X + PADD * 6, I_Y + PADD * 4, ft_itoa(mlx->z_max));
}

#else

static void	write_menu(t_mlx *mlx)
{
	write_white(mlx, IHEAD_X, IHEAD_Y, "### MAP INFO ###");
	write_white(mlx, I_X, I_Y, "Win width:");
	write_white(mlx, I_X, I_Y + PADD, "Win height:");
	write_white(mlx, I_X, I_Y + PADD * 2, "Max X:");
	write_white(mlx, I_X, I_Y + PADD * 3, "Max Y:");
	write_white(mlx, I_X, I_Y + PADD * 4, "Min Z:");
	write_white(mlx, I_X, I_Y + PADD * 5, "Max Z:");
	write_white(mlx, CHEAD_X, CHEAD_Y, "### CONTROLS ###");
	write_white(mlx, C_X, C_Y, "[Arrows] Move model");
	write_white(mlx, C_X, C_Y + PADD, "[Mouse wheel] Zoom in/out");
	write_white(mlx, C_X, C_Y + PADD * 2, "[Mouse left/right] Z index");
	write_white(mlx, C_X, C_Y + PADD * 3, "[W - S] Rotate Y angle");
	write_white(mlx, C_X, C_Y + PADD * 4, "[A - D] Rotate X angle");
	write_white(mlx, C_X, C_Y + PADD * 5, "[TAB] Alternate projection");
	write_white(mlx, C_X, C_Y + PADD * 6, "[SPACE] Alternate triangles");
	write_white(mlx, VHEAD_X, VHEAD_Y, "### VARIABLES ###");
	write_white(mlx, V_X, V_Y, "Shift X:");
	write_white(mlx, V_X, V_Y + PADD, "Shift Y:");
	write_white(mlx, V_X, V_Y + PADD * 2, "Angle X:");
	write_white(mlx, V_X, V_Y + PADD * 3, "Angle Y:");
	write_white(mlx, V_X, V_Y + PADD * 4, "Scale XY:");
	write_white(mlx, V_X, V_Y + PADD * 5, "Scale Z:");
	write_white(mlx, V_X, V_Y + PADD * 6, "Projection:");
	write_white(mlx, V_X, V_Y + PADD * 7, "Triagles:");
}

static void	write_vars(t_mlx *mlx)
{
	write_var(mlx, I_X + PADD * 6, I_Y, ft_itoa(mlx->width));
	write_var(mlx, I_X + PADD * 6, I_Y + PADD, ft_itoa(mlx->height));
	write_var(mlx, I_X + PADD * 6, I_Y + PADD * 2, ft_itoa(mlx->x_max));
	write_var(mlx, I_X + PADD * 6, I_Y + PADD * 3, ft_itoa(mlx->y_max));
	write_var(mlx, I_X + PADD * 6, I_Y + PADD * 4, ft_itoa(mlx->z_min));
	write_var(mlx, I_X + PADD * 6, I_Y + PADD * 5, ft_itoa(mlx->z_max));
	write_var(mlx, V_X + PADD * 6, V_Y, ft_itoa(mlx->x_shift));
	write_var(mlx, V_X + PADD * 6, V_Y + PADD, ft_itoa(mlx->y_shift));
	write_var(mlx, V_X + PADD * 6, V_Y + PADD * 2, ft_itoa(mlx->x_angle * 180));
	write_var(mlx, V_X + PADD * 6, V_Y + PADD * 3, ft_itoa(mlx->y_angle * 180));
	write_var(mlx, V_X + PADD * 6, V_Y + PADD * 4, ft_itoa(mlx->xy_scale * 10));
	write_var(mlx, V_X + PADD * 6, V_Y + PADD * 5, ft_itoa(mlx->z_scale * 10));
	if (!mlx->projection)
		mlx_string_put(mlx->mlx, mlx->win, V_X + PADD * 6, V_Y + PADD * 6,
			0x50fcba03, "ISOMETRIC");
	else
		mlx_string_put(mlx->mlx, mlx->win, V_X + PADD * 6, V_Y + PADD * 6,
			0x50fcba03, "PRESPECTIVE");
	if (mlx->triangles)
		mlx_string_put(mlx->mlx, mlx->win, V_X + PADD * 6, V_Y + PADD * 7,
			0x5000ff00, "ON");
	else
		mlx_string_put(mlx->mlx, mlx->win, V_X + PADD * 6, V_Y + PADD * 7,
			0x50ff0000, "OFF");
}

#endif

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
