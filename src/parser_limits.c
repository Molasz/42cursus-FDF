/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_limits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:25:56 by molasz-a          #+#    #+#             */
/*   Updated: 2024/03/05 22:18:45 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	count_x(char *line)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (line[i] && line[i] != '\n')
	{
		while (line[i] == ' ')
			i++;
		count++;
		while (line[i] != ' ' && line[i] != '\n' && line[i] != '\0')
			i++;
	}
	return (count);
}

static void	set_win_size(t_mlx *mlx)
{
	float	size;

	if (mlx->x_max > mlx->y_max)
	{
		mlx->width = WIN_SIZE;
		size = WIN_SIZE / 2.0 / (mlx->x_max + 1);
		mlx->height = size * (mlx->y_max + 1) + (WIN_SIZE / 2);
	}
	else
	{
		mlx->height = WIN_SIZE;
		size = WIN_SIZE / 2.0 / (mlx->y_max + 1);
		mlx->width = size * (mlx->x_max + 1) + (WIN_SIZE / 2);
	}
	mlx->x_shift = mlx->width / 2 + MENU_SIZE;
	mlx->y_shift = mlx->height / 2;
	mlx->xy_scale = size;
	mlx->z_max = 1;
	mlx->z_min = -1;
	mlx->x_angle = 0.4;
	mlx->y_angle = 0.4;
	mlx->projection = 0;
	mlx->triangles = 0;
}

int	parser_limits(char *f, t_mlx *mlx)
{
	char	*line;
	int		fd;
	int		x_max;

	fd = open(f, O_RDONLY);
	if (fd < 0)
		return (1);
	mlx->x_max = 0;
	mlx->y_max = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		mlx->y_max++;
		x_max = count_x(line);
		if (x_max > mlx->x_max)
			mlx->x_max = x_max;
		free(line);
	}
	set_win_size(mlx);
	return (0);
}
