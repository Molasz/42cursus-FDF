/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 00:32:19 by molasz-a          #+#    #+#             */
/*   Updated: 2024/03/03 12:36:17 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_len(unsigned int n)
{
	int	i;

	i = 0;
	while (n >= 10)
	{
		n /= 10;
		i++;
	}
	return (i + 1);
}

static unsigned int	ft_abs(int n, int *size)
{
	unsigned int	num;

	num = (unsigned int)n;
	if (n < 0)
	{
		num = (unsigned int)-n;
		*size += 1;
	}
	return (num);
}

char	*ft_itoa(int n)
{
	unsigned int	num;
	char			*str;
	int				str_size;
	int				str_count;

	str_size = 0;
	num = ft_abs(n, &str_size);
	str_size += num_len(num);
	str = malloc(sizeof (char) * (str_size + 1));
	if (!str)
		return (NULL);
	str[str_size] = 0;
	if (n < 0)
		str[0] = '-';
	str_count = str_size - 1;
	while ((n >= 0 && str_count >= 0) || (n < 0 && str_count))
	{
		str[str_count] = (num % 10) + '0';
		num /= 10;
		str_count--;
	}
	return (str);
}
