/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:27:12 by molasz-a          #+#    #+#             */
/*   Updated: 2024/02/21 17:30:12 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

int	on_close(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->win);
	mlx_destroy_image(mlx->mlx, mlx->img.img);
	printf("CLOSE mlx:%p win:%p img:%p\n", mlx->mlx, mlx->win, mlx->img.img);
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

	if (argc && argv)
	{
		mlx.mlx = mlx_init();
		mlx.win = mlx_new_window(mlx.mlx, 1280, 720, "FDF");
		mlx.img.img = mlx_new_image(mlx.mlx, 1280, 720);
		mlx.img.addr = mlx_get_data_addr(mlx.img.img,
				&mlx.img.bpp, &mlx.img.line_len, &mlx.img.endian);
		put_pixel(&mlx.img, 5, 5, 0x00FF0000);
		put_pixel(&mlx.img, 1275, 715, 0x00FF0000);
		mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img.img, 0 , 0);
		mlx_hook(mlx.win, ON_KEYUP, 0, on_key, &mlx);
		mlx_hook(mlx.win, ON_DESTROY, 0, on_close, &mlx);
		mlx_loop(mlx.mlx);
	}
	return (0);
}
