/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:58:28 by molasz-a          #+#    #+#             */
/*   Updated: 2024/02/29 16:45:17 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	read_color(t_list *lst, char *s)
{
	if (*s == ',')
	{
		lst->r = ft_atohex(s + 3);
		if (s[5] != ' ')
			lst->g = ft_atohex(s + 5);
		if (s[5] != ' ' && s[7] != ' ')
			lst->b = ft_atohex(s + 7);
	}
	else
	{
		lst->r = 255;
		lst->g = 255;
		lst->b = 255;
	}
}

static int	read_line(t_list **lst, char *s, int y, t_mlx *mlx)
{
	t_list	*new;
	int		x;
	int		i;

	i = 0;
	x = 0;
	while (s[i] != '\n' && s[i])
	{
		while (s[i] == ' ')
			i++;
		new = ft_lstnew(x, y, ft_atoi(s + i));
		if (!new)
			return (1);
		while (s[i] >= '0' && s[i] <= '9')
			i++;
		read_color(new, s + i);
		ft_lstadd_back(lst, new);
		while (s[i] != ' ' && s[i])
			i++;
		x++;
	}
	mlx->max_x = new->x;
	mlx->max_y = new->y;
	return (0);
}

static int	read_file(int fd, t_list **lst, t_mlx *mlx)
{
	char	*line;
	int		y;

	y = 0;
	while (y >= 0)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (read_line(lst, line, y, mlx))
			return (1);
		free(line);
		y++;
	}
	return (0);
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

t_list	*parser(char *file, t_mlx *mlx)
{
	int		fd;
	t_list	*lst;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	lst = NULL;
	if (read_file(fd, &lst, mlx))
		return (NULL);
	set_win_size(mlx);
	return (lst);
}
