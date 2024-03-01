/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:44:07 by molasz-a          #+#    #+#             */
/*   Updated: 2024/03/01 18:00:31 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	calc_color(t_mlx *mlx, t_color *color, t_point start, t_point end)
{
	color->r = mlx->coords[start.y][start.x].r;
	color->g = mlx->coords[start.y][start.x].g;
	color->b = mlx->coords[start.y][start.x].b;
	color->dr = mlx->coords[end.y][end.x].r - mlx->coords[start.y][start.x].r;
	color->dg = mlx->coords[end.y][end.x].g - mlx->coords[start.y][start.x].g;
	color->db = mlx->coords[end.y][end.x].b - mlx->coords[start.y][start.x].b;
}

static void	calc_line(t_mlx *mlx, t_point start, t_point end)
{
	t_color	color;
	int		z;
	double	x_angle;
	double	y_angle;

	x_angle = mlx->x_angle / 180.0;
	y_angle = mlx->y_angle / 180.0;
	calc_color(mlx, &color, start, end);
	z = mlx->coords[start.y][start.x].z * mlx->z_scale * mlx->xy_scale;
	start.x *= mlx->xy_scale;
	start.y *= mlx->xy_scale;
	start.x = (start.x - start.y) * cos(x_angle);
	start.y = (start.x + start.y) * sin(y_angle) - z;
	start.x += mlx->x_shift;
	start.y += mlx->y_shift;
	z = mlx->coords[end.y][end.x].z * mlx->z_scale * mlx->xy_scale;
	end.x *= mlx->xy_scale;
	end.y *= mlx->xy_scale;
	end.x = (end.x - end.y) * cos(x_angle);
	end.y = (end.x + end.y) * sin(y_angle) - z;
	end.x += mlx->x_shift;
	end.y += mlx->y_shift;
	draw_line(mlx, start, end, &color);
}

static void	connect_pixels(t_mlx *mlx)
{
	int		x;
	int		y;

	y = 0;
	while (y < mlx->y_max)
	{
		x = 0;
		while (x < mlx->x_max)
		{
			if (x + 1 < mlx->x_max)
				calc_line(mlx, (t_point){x, y}, (t_point){x + 1, y});
			if (y + 1 < mlx->y_max)
				calc_line(mlx, (t_point){x, y}, (t_point){x, y + 1});
			x++;
		}
		y++;
	}
}

int	new_image(t_mlx *mlx, t_img *img)
{
	if (mlx->img == img)
		mlx_destroy_image(mlx->mlx, img->img);
	img->img = mlx_new_image(mlx->mlx, mlx->width, mlx->height);
	if (!img->img)
		return (1);
	img->addr = mlx_get_data_addr(img->img,
			&img->bpp, &img->line_len, &img->endian);
	mlx->img = img;
	connect_pixels(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, img->img, 0, 0);
	return (0);
}
