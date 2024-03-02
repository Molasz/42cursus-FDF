/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enums.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 13:18:51 by molasz-a          #+#    #+#             */
/*   Updated: 2024/03/03 00:29:10 by molasz-a         ###   ########.fr       */
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
	SPACE = 20,
	CHEAD_X = 65,
	CHEAD_Y = 5,
	C_X = 15,
	C_Y = 30,
	IHEAD_X = 55,
	IHEAD_Y = 150,
	I_X = 25,
	I_Y = 175,
	VHEAD_X = 70,
	VHEAD_Y = 300,
	V_X = 25,
	V_Y = 325
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
	CHEAD_X = 50,
	CHEAD_Y = 25,
	C_X = 15,
	C_Y = 50,
	IHEAD_X = 55,
	IHEAD_Y = 175,
	I_X = 25,
	I_Y = 200,
	VHEAD_X = 50,
	VHEAD_Y = 325,
	V_X = 25,
	V_Y = 350
};

# endif

#endif
