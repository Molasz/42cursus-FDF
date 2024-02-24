/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:58:28 by molasz-a          #+#    #+#             */
/*   Updated: 2024/02/24 16:32:58 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	read_line(t_list **lst, char *s, int y)
{
	t_list	*new;
	int		x;
	int		i;

	i = 0;
	x = 0;
	while (s[i] != '\n' && s[i])
	{
		new = ft_lstnew(x, y, ft_atoi_base(s + i, "0123456789"));
		if (!new)
			return (1);
		while (s[i] >= '0' && s[i] <= '9')
			i++;
		if (s[i] == ',')
			new->color = ft_atoi_base(s + i + 3, "0123456789ABCDEF");
		ft_lstadd_back(lst, new);
		while (s[i] != ' ' && s[i])
			i++;
		while (s[i] == ' ')
			i++;
		x++;
	}
	return (0);
}

static int	read_file(int fd, t_list **lst)
{
	char	*line;
	int		y;
	
	y = 0;
	while (y >= 0)
	{
		printf("READING LINE %d\n", y);
		line = get_next_line(fd);
		if (!line)
			break ;
		if (read_line(lst, line, y))
			return (1);
		free(line);
		y++;
	}
	return (0);
}

static void	calc_coords(t_list *lst)
{
	t_list	*tmp;
	int		size_x;
	int		size_y;

	tmp = ft_lstlast(lst);
	size_x = (WIDTH - (SPACE * 2)) / tmp->x;
	size_y = (HEIGHT - (SPACE * 2)) / tmp->y;
	tmp = lst;
	while (tmp)
	{
		tmp->x = tmp->x * size_x + SPACE;
		tmp->y = tmp->y * size_y + SPACE;
		tmp = tmp->next;
	}
}

t_list	*parser(char *file)
{
	int		fd;
	t_list	*lst;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	lst = NULL;
	if (read_file(fd, &lst))
		return (NULL);
	calc_coords(lst);
	return (lst);
}
