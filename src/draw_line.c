/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 16:50:06 by molasz-a          #+#    #+#             */
/*   Updated: 2024/03/05 00:55:02 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	put_pixel(t_mlx *mlx, int x, int y, t_color *color)
{
	char	*dst;

	if (x < 0 || x >= mlx->width + MENU_SIZE || y < 0 || y >= mlx->height)
		return ;
	dst = mlx->img->addr + (y * mlx->img->line_len + x * (mlx->img->bpp / 8));
	*(unsigned int *)dst = ((int) color->r << 16
			| (int) color->g << 8 | (int) color->b);
}

static void	update_color(t_color *color)
{
	color->r += color->dr;
	color->g += color->dg;
	color->b += color->db;
}

static int	invalid_coord(t_mlx *mlx, t_point *coord)
{
	if (coord->x < 0 || coord->x >= mlx->width + MENU_SIZE
		|| coord->y < 0 || coord->y >= mlx->height)
		return (1);
	return (0);
}

void	draw_line(t_mlx *mlx, t_point *start, t_point *end, t_color *color)
{
	t_foint	diff;
	t_foint	pixel;
	double	steps;

	if (invalid_coord(mlx, start) && invalid_coord(mlx, end))
		return ;
	pixel.x = start->x;
	pixel.y = start->y;
	diff.x = end->x - start->x;
	diff.y = end->y - start->y;
	steps = sqrt(diff.x * diff.x + diff.y * diff.y);
	diff.x /= steps;
	diff.y /= steps;
	color->dr /= steps;
	color->dg /= steps;
	color->db /= steps;
	steps = (int) steps;
	while (steps-- > 0)
	{
		put_pixel(mlx, pixel.x, pixel.y, color);
		pixel.x += diff.x;
		pixel.y += diff.y;
		update_color(color);
	}
}
