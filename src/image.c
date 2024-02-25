/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:44:07 by molasz-a          #+#    #+#             */
/*   Updated: 2024/02/25 19:56:58 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	calc_color(t_color *color, t_color *start, t_color *end)
{
	color->t = start->t;
	color->r = start->r;
	color->g = start->g;
	color->b = start->b;
	color->dt = end->t - start->t;
	color->dr = end->r - start->r;
	color->dg = end->g - start->g;
	color->db = end->b - start->b;
}

static void	connect_pixels(t_mlx *mlx)
{
	t_color	color;
	t_list	*lst;
	t_list	*next_line;

	lst = mlx->coords;
	next_line = lst;
	while (next_line->y == lst->y)
		next_line = next_line->next;
	while (lst->next)
	{
		if (lst->y == lst->next->y)
			calc_color(&color, &lst->color, &lst->next->color);
		if (lst->y == lst->next->y)
			draw_line(mlx->img, (t_point){lst->x, lst->y},
				(t_point){lst->next->x, lst->next->y}, &color);
		if (next_line)
			calc_color(&color, &lst->color, &next_line->color);
		if (next_line)
			draw_line(mlx->img, (t_point){lst->x, lst->y},
				(t_point){next_line->x, next_line->y}, &color);
		lst = lst->next;
		if (next_line)
			next_line = next_line->next;
	}
}

int	new_image(t_mlx *mlx, t_img *img)
{
	if (mlx->img)
		mlx_destroy_image(mlx->mlx, mlx->img->img);
	img->img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	if (!img->img)
		return (1);
	img->addr = mlx_get_data_addr(img->img,
			&img->bpp, &img->line_len, &img->endian);
	mlx->img = img;
	connect_pixels(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, img->img, 0, 0);
	return (0);
}
