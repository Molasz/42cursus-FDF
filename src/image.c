/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:44:07 by molasz-a          #+#    #+#             */
/*   Updated: 2024/02/29 16:37:55 by molasz-a         ###   ########.fr       */
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
	printf("NEXT:%d %d\n", next_line->x, next_line->y);
	while (lst->next)
	{
		if (lst->y != mlx->max_y)
		{
			printf("HORITZONTAL\n");
			calc_color(&color, lst, lst->next);
			draw_line(mlx, (t_point){lst->x, lst->y},
				(t_point){lst->next->x, lst->next->y}, &color);
		}
		if (next_line)
		{
			printf("VERTICAL\n");
			calc_color(&color, lst, next_line);
			draw_line(mlx, (t_point){lst->x, lst->y},
				(t_point){next_line->x, next_line->y}, &color);
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
