/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 16:50:06 by molasz-a          #+#    #+#             */
/*   Updated: 2024/02/25 19:59:45 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	put_pixel(t_img *img, int x, int y, t_color *color)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = (color->t << 24 | color->r << 16 | color->g << 8 | color->b);
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

static void	update_color(t_color *color, int pxc)
{
	color->t += color->dt / pxc;
	color->r += color->dr / pxc;
	color->g += color->dg / pxc;
	color->b += color->db / pxc;
	printf("r:%d g:%d b:%d\n", color->r, color->g, color->b);
}

void	draw_line(t_img *img, t_point start, t_point end, t_color *color)
{
	t_point	d;
	t_point	s;
	int		err;
	int		pxc;

	init_line(start, end, &s, &d);
	err = d.x + d.y;
	pxc = sqrt((d.x * d.x) + (d.y * d.y));
	while (1)
	{
		put_pixel(img, start.x, start.y, color);
		if (start.x == end.x && start.y == end.y)
			break ;
		update_point(&d, &s, &start, &err);
		update_color(color, pxc);
	}
}
