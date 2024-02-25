/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:44:07 by molasz-a          #+#    #+#             */
/*   Updated: 2024/02/25 00:52:53 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

int	new_image(t_mlx *mlx, t_img *img)
{
	t_list	*lst;
	t_list	*tmp;

	img->img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	if (!img->img)
		return (1);
	img->addr = mlx_get_data_addr(img->img,
			&img->bpp, &img->line_len, &img->endian);
	mlx->img = img;
	lst = mlx->coords;
	while (lst->next)
	{
		if (lst->y == lst->next->y)
			draw_line(mlx->img, (t_point){lst->x, lst->y},
					(t_point){lst->next->x, lst->next->y});
		tmp = ft_lstlast(lst); // TODO size_x 
		tmp = ft_lstget(lst, tmp->x + 1);
		if (tmp)
		{
			printf("%d %d\n", tmp->x, tmp->y);
			draw_line(mlx->img, (t_point){lst->x, lst->y},
					(t_point){tmp->x, tmp->y});
		}
		lst = lst->next;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, img->img, 0, 0);
	return (0);
}
