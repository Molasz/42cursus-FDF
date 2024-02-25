/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 16:50:06 by molasz-a          #+#    #+#             */
/*   Updated: 2024/02/25 00:14:30 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	init_line(t_point start, t_point end, t_point *s, t_point *d)
{
	d->x = abs(end.x - start.x);
	d->y = -abs(end.y - start.y);
	if (start.x < end.x)
		s->x = 1;
	else
		s->x = -1;
	if (start.y - start.x)
		s->y = 1;
	else
		s->y = -1;
}

void	draw_line(t_img *img, t_point start, t_point end)
{
	t_point	d;
	t_point	s;
	int		err;
	int		err2;

	init_line(start, end, &s, &d);
	err = d.x + d.y;
	while (1)
	{
		put_pixel(img, start.x, start.y, 0x00FFFFFF);
		if (start.x == end.x && start.y == end.y)
			break ;
		err2 = 2 * err;
		if (err2 >= d.y)
		{
			err += d.y;
			start.x += s.x;
		}
		if (err2 <= d.x)
		{
			err += d.x;
			start.y += s.y;
		}
	}
}
