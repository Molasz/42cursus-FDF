/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:58:28 by molasz-a          #+#    #+#             */
/*   Updated: 2024/02/28 21:43:27 by molasz-a         ###   ########.fr       */
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

static int	read_line(t_list **lst, char *s, int y)
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
	return (0);
}

static int	read_file(int fd, t_list **lst)
{
	char	*line;
	int		y;

	y = 0;
	while (y >= 0)
	{
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
	return (lst);
}
