/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:44:07 by molasz-a          #+#    #+#             */
/*   Updated: 2024/02/22 15:17:26 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

void	new_image(t_mlx *mlx, t_img *img)
{
	img->img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(img->img,
			&img->bpp, &img->line_len, &img->endian);
	mlx->img = img;
	put_pixel(img, 5, 5, 0x00FF0000);
	put_pixel(img, 1275, 715, 0x00FF0000);
	mlx_put_image_to_window(mlx->mlx, mlx->win, img->img, 0, 0);
}
