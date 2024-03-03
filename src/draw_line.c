/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 16:50:06 by molasz-a          #+#    #+#             */
/*   Updated: 2024/03/03 17:09:53 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	put_pixel(t_mlx *mlx, int x, int y, t_color *color)
{
	char	*dst;

	if (x < 0 || x >= mlx->width || y < 0 || y >= mlx->height)
		return ;
	dst = mlx->img->addr + (y * mlx->img->line_len + x * (mlx->img->bpp / 8));
	*(unsigned int *)dst = (color->r << 16 | color->g << 8 | color->b);
}

static void	update_color(t_color *color)
{
	if ((color->dr > 0 && color->r + color->dr < 255)
		|| (color->dr < 0 && color->r + color->dr > 0))
		color->r += color->dr;
	if ((color->dg > 0 && color->g + color->dg < 255)
		|| (color->dg < 0 && color->g + color->dg > 0))
		color->g += color->dg;
	if ((color->db > 0 && color->b + color->db < 255)
		|| (color->db < 0 && color->b + color->db > 0))
		color->b += color->db;
}

static int	invalid_coord(t_mlx *mlx, t_point *coord)
{
	if (coord->x < 0 || coord->x >= mlx->width
		|| coord->y < 0 || coord->y >= mlx->height)
		return (1);
	return (0);
}

void	draw_line(t_mlx *mlx, t_point start, t_point end, t_color *color)
{
	t_foint	diff;
	t_foint	pixel;
	int		steps;

	if (invalid_coord(mlx, &start) && invalid_coord(mlx, &end))
		return ;
	diff.x = end.x - start.x;
	diff.y = end.y - start.y;
	steps = sqrt(diff.x * diff.x + diff.y * diff.y) + 1;
	diff.x /= steps;
	diff.y /= steps;
	color->dr = color->dr / steps;
	color->dg = color->dg / steps;
	color->db = color->db / steps;
	pixel.x = start.x;
	pixel.y = start.y;
	while (steps > 0)
	{
		put_pixel(mlx, pixel.x, pixel.y, color);
		pixel.x += diff.x;
		pixel.y += diff.y;
		update_color(color);
		steps--;
	}
}

void	calc_color(t_mlx *mlx, t_color *color, t_point start, t_point end)
{
	color->r = mlx->coords[start.y][start.x].r;
	color->g = mlx->coords[start.y][start.x].g;
	color->b = mlx->coords[start.y][start.x].b;
	color->dr = mlx->coords[end.y][end.x].r - mlx->coords[start.y][start.x].r;
	color->dg = mlx->coords[end.y][end.x].g - mlx->coords[start.y][start.x].g;
	color->db = mlx->coords[end.y][end.x].b - mlx->coords[start.y][start.x].b;
}
