/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_limits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:25:56 by molasz-a          #+#    #+#             */
/*   Updated: 2024/02/29 18:10:02 by molasz-a         ###   ########.fr       */
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

	if (mlx->max_x > mlx->max_y)
	{
		mlx->width = SIZE;
		size = SIZE / 2 / (mlx->max_x + 0.0);
		mlx->height = size * (mlx->max_y + 1) + (SIZE / 2);
	}
	else
	{
		mlx->height = SIZE;
		size = SIZE / 2 / (mlx->max_y + 0.0);
		mlx->width = size * (mlx->max_x + 1) + (SIZE / 2);
	}
	mlx->x_shift = SIZE / 4;
	mlx->y_shift = SIZE / 4;
	mlx->scale = size;
	mlx->zscale = 10;
	mlx->angle = 160;
}

int	parser_limits(char *f, t_mlx *mlx)
{
	char	*line;
	int		fd;
	int		max_x;

	fd = open(f, O_RDONLY);
	if (fd < 0)
		return (1);
	mlx->max_x = 0;
	mlx->max_y = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		mlx->max_y++;
		max_x = count_x(line);
		if (max_x > mlx->max_x)
			mlx->max_x = max_x;
		free(line);
	}
	set_win_size(mlx);
	return (0);
}
