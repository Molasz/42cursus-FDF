/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enums.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 13:18:51 by molasz-a          #+#    #+#             */
/*   Updated: 2024/03/03 16:52:21 by molasz-a         ###   ########.fr       */
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
	TAB = 48
};

enum
{
	MENU_SIZE = 300,
	SPACE = 25,
	IHEAD_X = 55,
	IHEAD_Y = 5,
	I_X = 25,
	I_Y = 30,
	CHEAD_X = 60,
	CHEAD_Y = 190,
	C_X = 15,
	C_Y = 215,
	VHEAD_X = 50,
	VHEAD_Y = 360,
	V_X = 25,
	V_Y = 385
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
	TAB = 65289
};

enum
{
	MENU_SIZE = 240,
	SPACE = 20,
	IHEAD_X = 55,
	IHEAD_Y = 25,
	I_X = 25,
	I_Y = 70,
	CHEAD_X = 50,
	CHEAD_Y = 195,
	C_X = 15,
	C_Y = 220,
	VHEAD_X = 50,
	VHEAD_Y = 345,
	V_X = 25,
	V_Y = 370
};

# endif

#endif
