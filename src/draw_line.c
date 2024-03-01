/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 16:50:06 by molasz-a          #+#    #+#             */
/*   Updated: 2024/03/01 12:19:18 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	put_pixel(t_mlx *mlx, int x, int y, t_color *color)
{
	char	*dst;

	if (x < 0 || x > mlx->width || y < 0 || y > mlx->height)
		return ;
	dst = mlx->img->addr + (y * mlx->img->line_len + x * (mlx->img->bpp / 8));
	*(unsigned int *)dst = (color->r << 16 | color->g << 8 | color->b);
}

static void	init_line(t_point start, t_point end, t_point *s, t_point *d)
{
	d->x = abs(end.x - start.x);
	d->y = -abs(end.y - start.y);
	if (start.x < end.x)
		s->x = 1;
	else
		s->x = -1;
	if (start.y < end.y)
		s->y = 1;
	else
		s->y = -1;
}

static void	update_point(t_point *d, t_point *s, t_point *start, int *err)
{
	if (*err * 2 >= d->y)
	{
		*err += d->y;
		start->x += s->x;
	}
	if (*err * 2 <= d->x)
	{
		*err += d->x;
		start->y += s->y;
	}
}

static void	update_color(t_color *color)
{
	color->r += color->dr;
	color->g += color->dg;
	color->b += color->db;
}

void	draw_line(t_mlx *mlx, t_point start, t_point end, t_color *color)
{
	t_point	d;
	t_point	s;
	int		err;
	int		pxc;

	init_line(start, end, &s, &d);
	err = d.x + d.y;
	pxc = sqrt((d.x * d.x) + (d.y * d.y));
	color->dr = color->dr / pxc;
	color->dg = color->dg / pxc;
	color->db = color->db / pxc;
	while (1)
	{
		put_pixel(mlx, start.x, start.y, color);
		if (start.x >= end.x && start.y >= end.y)
			break ;
		update_point(&d, &s, &start, &err);
		update_color(color);
	}
}
