/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:44:07 by molasz-a          #+#    #+#             */
/*   Updated: 2024/02/29 17:24:05 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	calc_color(t_color *color, t_list *start, t_list *end)
{
	color->r = start->r;
	color->g = start->g;
	color->b = start->b;
	color->dr = end->r - start->r;
	color->dg = end->g - start->g;
	color->db = end->b - start->b;
}

static void	calc_line(t_mlx *mlx, t_color *color, t_list *start, t_list *end)
{
	calc_color(color, start, end);
	draw_line(mlx, (t_point){start->x, start->y},
		(t_point){end->x, end->y}, color);
}

static void	connect_pixels(t_mlx *mlx)
{
	t_color	color;
	t_list	*lst;
	t_list	*next_line;
	int		i;

	lst = mlx->coords;
	next_line = lst;
	i = 0;
	while (i++ <= mlx->max_x)
		next_line = next_line->next;
	while (lst->next)
	{
		if (lst->y != mlx->max_y)
			calc_line(mlx, &color, lst, lst->next);
		if (next_line)
		{
			calc_line(mlx, &color, lst, next_line);
			next_line = next_line->next;
		}
		lst = lst->next;
	}
}

int	new_image(t_mlx *mlx, t_img *img)
{
	if (img->img)
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
