/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:58:28 by molasz-a          #+#    #+#             */
/*   Updated: 2024/02/29 20:32:21 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	read_color(t_coord *coord, char *s)
{
	if (*s == ',')
	{
		coord->r = ft_atohex(s + 3);
		if (s[5] != ' ')
			coord->g = ft_atohex(s + 5);
		if (s[5] != ' ' && s[7] != ' ')
			coord->b = ft_atohex(s + 7);
	}
	else
	{
		coord->r = 255;
		coord->g = 255;
		coord->b = 255;
	}
}

static t_coord	*read_line(char *line, t_mlx *mlx)
{
	t_coord	*coords;
	int		x;
	int		i;

	coords = malloc((mlx->max_x) * sizeof (t_coord));
	if (!coords)
		return (NULL);
	i = 0;
	x = 0;
	while (line[i] != '\n' && line[i])
	{
		while (line[i] == ' ')
			i++;
		coords[x].z = ft_atoi(line + i);
		while (line[i] >= '0' && line[i] <= '9')
			i++;
		read_color(coords + x, line + i);
		while (line[i] != ' ' && line[i])
			i++;
		x++;
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

	coords = malloc((mlx->max_y) * sizeof (t_coord **));
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
