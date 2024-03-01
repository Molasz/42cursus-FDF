/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 16:50:06 by molasz-a          #+#    #+#             */
/*   Updated: 2024/03/01 22:59:05 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	put_pixel(t_mlx *mlx, int x, int y, t_color *color)
{
	char	*dst;

	if (x < 0 || x >= mlx->width || y < 0 || y >= mlx->height)
		return ;
	dst = mlx->img->addr + (y * mlx->img->line_len + x * (mlx->img->bpp / 8));
	if (*dst)
		return ;
	*(unsigned int *)dst = (color->r << 16 | color->g << 8 | color->b);
}

static void	update_color(t_color *color)
{
	color->r += color->dr;
	color->g += color->dg;
	color->b += color->db;
}

static	int	out_pixel(t_mlx *mlx, t_point p)
{
	if (p.x < 0 || p.x >= mlx->width || p.y < 0 || p.y >= mlx->height)
		return (1);
	return (0);
}

void	draw_line(t_mlx *mlx, t_point start, t_point end, t_color *color)
{
	t_point	diff;
	t_point	pixel;
	int		steps;

	if (out_pixel(mlx, start) && out_pixel(mlx, end))
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
