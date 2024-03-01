/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enums.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 13:18:51 by molasz-a          #+#    #+#             */
/*   Updated: 2024/03/01 14:14:00 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUMS_H
# define ENUMS_H

enum
{
	ON_DESTROY = 17
};

# ifndef LINUX

enum
{
	ESC = 53,
	UP = 123,
	DOWN = 124,
	RIGHT = 125,
	LEFT = 126
};

# else

enum
{
	ESC = 65307,
	UP = 65362,
	DOWN = 65364,
	RIGHT = 65636,
	LEFT = 65361
};

# endif

#endif
