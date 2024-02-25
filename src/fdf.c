/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:27:12 by molasz-a          #+#    #+#             */
/*   Updated: 2024/02/25 00:12:51 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
static void	print_lst(t_list *lst)
{
	while (lst)
	{
		printf("[%d,%d,%d] (%d)\n", lst->x, lst->y, lst->z, lst->color);
		lst = lst->next;
	}
}
*/

static int	on_close(t_mlx *mlx)
{
	if (mlx->img)
		mlx_destroy_image(mlx->mlx, mlx->img->img);
	ft_lstclear(&mlx->coords);
	mlx_destroy_window(mlx->mlx, mlx->win);
	exit(0);
	return (0);
}

static int	on_key(int n, t_mlx *mlx)
{
	if (n == 53)
		on_close(mlx);
	return (0);
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;
	t_img	img;

	if (argc == 2)
	{
		mlx.mlx = mlx_init();
		if (!mlx.mlx)
			return (1);
		mlx.coords = parser(argv[1]);
		if (!mlx.coords)
			return (1);
		mlx.win = mlx_new_window(mlx.mlx, WIDTH, HEIGHT, "FDF");
		if (!mlx.win || new_image(&mlx, &img))
		{
			ft_lstclear(&mlx.coords);
			return (1);
		}
		mlx_hook(mlx.win, ON_KEYUP, 0, on_key, &mlx);
		mlx_hook(mlx.win, ON_DESTROY, 0, on_close, &mlx);
		mlx_loop(mlx.mlx);
	}
	return (0);
}
