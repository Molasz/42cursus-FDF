/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:27:12 by molasz-a          #+#    #+#             */
/*   Updated: 2024/02/29 17:17:53 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	print_lst(t_list *lst)
{
	while (lst)
	{
		printf("[%d,%d,%d]\n", lst->x, lst->y, lst->z);
		lst = lst->next;
	}
}

static int	on_error(t_mlx *mlx)
{
	ft_lstclear(&mlx->coords);
	return (1);
}

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
	printf("%d\n", n);
	if (n == 53)
		on_close(mlx);
	if (n == 49)
	{
		calc_coords(mlx);
		new_image(mlx, mlx->img);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;
	t_img	img;

	if (argc == 2)
	{
		mlx.coords = parser(argv[1], &mlx);
		if (!mlx.coords)
			return (1);
		calc_coords(&mlx);
		mlx.mlx = mlx_init();
		if (!mlx.mlx)
			on_error(&mlx);
		mlx.win = mlx_new_window(mlx.mlx, mlx.width, mlx.height, "FDF");
		if (!mlx.win || new_image(&mlx, &img))
			on_error(&mlx);
		mlx_hook(mlx.win, ON_KEYUP, 0, on_key, &mlx);
		mlx_hook(mlx.win, ON_DESTROY, 0, on_close, &mlx);
		mlx_loop(mlx.mlx);
	}
	return (0);
}
