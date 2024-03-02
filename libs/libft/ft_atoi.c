/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 20:09:29 by molasz-a          #+#    #+#             */
/*   Updated: 2024/03/03 00:32:01 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int	i;
	int	count;
	int	sign;

	i = 0;
	sign = 1;
	count = 0;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		count *= 10;
		count += str[i] - '0';
		i++;
	}
	return (count * sign);
}

int	ft_atohex(const char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] && i < 2)
	{
		count *= 16;
		if (str[i] >= '0' && str[i] <= '9')
			count += str[i] - '0';
		else if (str[i] >= 'A' && str[i] <= 'Z')
			count += str[i] - 'A' + 10;
		else if (str[i] >= 'a' && str[i] <= 'z')
			count += str[i] - 'a' + 10;
		else
			break ;
		i++;
	}
	return (count);
}
