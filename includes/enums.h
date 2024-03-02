/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enums.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 13:18:51 by molasz-a          #+#    #+#             */
/*   Updated: 2024/03/02 14:31:57 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUMS_H
# define ENUMS_H

enum
{
	ON_KEYDOWN = 2,
	ON_DESTROY = 17
};

# ifndef LINUX

enum
{
	ESC = 53,
	UP = 126,
	DOWN = 125,
	RIGHT = 124,
	LEFT = 123,
	W = 13,
	A = 0,
	S = 1,
	D = 2,
	MOUSE_UP = 4,
	MOUSE_DOWN = 5,
	ISOMETRIC = 18,
	PRESPETIVE = 19
};

# else

enum
{
	ESC = 65307,
	UP = 65362,
	DOWN = 65364,
	RIGHT = 65363,
	LEFT = 65361,
	W = 119,
	A = 97,
	S = 115,
	D = 100,
	MOUSE_UP = 4,
	MOUSE_DOWN = 5,
	ISOMETRIC = 49,
	PRESPETIVE = 50
};

# endif

#endif
