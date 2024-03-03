/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:58:28 by molasz-a          #+#    #+#             */
/*   Updated: 2024/03/03 16:40:00 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	read_color(t_coord *coord, char *s)
{
	coord->r = 0;
	coord->g = 0;
	coord->b = 0;
	if (*s == ',')
	{
		coord->r = ft_atohex(s + 3);
		if (s[5] != ' ')
			coord->g = ft_atohex(s + 5);
		if (s[5] != ' ' && s[7] != ' ')
			coord->b = ft_atohex(s + 7);
	}
}

static t_coord	*read_line(char *line, t_mlx *mlx)
{
	t_coord	*coords;
	int		x;
	int		i;

	coords = malloc((mlx->x_max) * sizeof (t_coord));
	if (!coords)
		return (NULL);
	i = 0;
	x = 0;
	while (line[i] != '\n' && line[i])
	{
		while (line[i] == ' ')
			i++;
		coords[x].z = ft_atoi(line + i);
		if (coords[x].z > mlx->z_max)
			mlx->z_max = coords[x].z;
		else if (coords[x].z < mlx->z_min)
			mlx->z_min = coords[x].z;
		while (line[i] >= '0' && line[i] <= '9')
			i++;
		read_color(coords + x++, line + i);
		while (line[i] != ' ' && line[i])
			i++;
	}
	return (coords);
}

static int	on_error_free(t_coord **coords)
{
	int	i;

	i = 0;
	while (coords[i])
		free(coords[i++]);
	free(coords);
	return (1);
}

static int	read_file(int fd, t_mlx *mlx)
{
	t_coord	**coords;
	char	*line;
	int		y;

	coords = malloc((mlx->y_max) * sizeof (t_coord **));
	if (!coords)
		return (1);
	y = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		coords[y] = read_line(line, mlx);
		free(line);
		if (!coords[y])
			return (on_error_free(coords));
		y++;
	}
	mlx->z_scale = 10.0 / mlx->z_max;
	mlx->coords = coords;
	return (0);
}

int	parser(char *file, t_mlx *mlx)
{
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (1);
	if (read_file(fd, mlx))
		return (1);
	return (0);
}
