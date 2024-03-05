/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:44:07 by molasz-a          #+#    #+#             */
/*   Updated: 2024/03/05 03:00:26 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	calc_color(t_color *color, t_coord *start, t_coord *end)
{
	color->r = start->r;
	color->g = start->g;
	color->b = start->b;
	color->dr = end->r - start->r;
	color->dg = end->g - start->g;
	color->db = end->b - start->b;
}

static void	draw_lines(t_mlx *mlx, int x, int y)
{
	t_color	color;

	if (x + 1 < mlx->x_max)
	{
		calc_color(&color, &mlx->coords[y][x], &mlx->coords[y][x + 1]);
		draw_line(mlx, &mlx->points[y][x], &mlx->points[y][x + 1], &color);
	}
	if (y + 1 < mlx->y_max)
	{
		calc_color(&color, &mlx->coords[y][x], &mlx->coords[y + 1][x]);
		draw_line(mlx, &mlx->points[y][x], &mlx->points[y + 1][x], &color);
	}
	if (mlx->triangles && x + 1 < mlx->x_max && y + 1 < mlx->y_max)
	{
		calc_color(&color, &mlx->coords[y][x], &mlx->coords[y + 1][x + 1]);
		draw_line(mlx, &mlx->points[y][x], &mlx->points[y + 1][x + 1], &color);
	}
}

static void	connect_pixels(t_mlx *mlx)
{
	int		x;
	int		y;

	y = -1;
	while (++y < mlx->y_max)
	{
		x = -1;
		while (++x < mlx->x_max)
			draw_lines(mlx, x, y);
	}
}

int	new_image(t_mlx *mlx, t_img *img)
{
	if (mlx->img == img)
		mlx_destroy_image(mlx->mlx, img->img);
	img->img = mlx_new_image(mlx->mlx, mlx->width + MENU_SIZE, mlx->height);
	if (!img->img)
		return (1);
	img->addr = mlx_get_data_addr(img->img,
			&img->bpp, &img->line_len, &img->endian);
	mlx->img = img;
	calc_coords(mlx);
	connect_pixels(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, img->img, 0, 0);
	return (0);
}
