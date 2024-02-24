/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:58:28 by molasz-a          #+#    #+#             */
/*   Updated: 2024/02/24 12:11:31 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	read_line(t_list **lst, char *s, int z)
{
	t_list	*new;
	int		x;
	int		i;

	i = 0;
	x = 0;
	while (s[i] != '\n' && s[i])
	{
		new = ft_lstnew(x, ft_atoi_base(s + i, "0123456789"), z);
		if (!new)
			return (1);
		while (s[i] >= '0' && s[i] <= '9')
			i++;
		if (s[i] == ',')
			new->color = ft_atoi_base(s + i + 3, "0123456789ABCDEF");
		ft_lstadd_back(lst, new);
		while (s[i] != ' ' && s[i])
			i++;
		i++;
		x++;
	}
	return (0);
}

int	read_file(int fd, t_list **lst)
{
	char	*line;
	int		z;
	
	z = 0;
	line = (char *)1;
	while (line)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (read_line(lst, line, z))
			return (1);
		free(line);
		z++;
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
