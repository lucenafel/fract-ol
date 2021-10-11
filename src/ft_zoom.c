/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zoom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfelipe- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 19:21:51 by lfelipe-          #+#    #+#             */
/*   Updated: 2021/10/11 23:31:56 by lfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractals.h"

void	ft_zoom_in(int d, int x, int y, t_cords *cords)
{
	double	rx;
	double	ry;
	double	dx;
	double	dy;

	rx = x / (double)WIDTH;
	ry = y / (double)HEIGHT;
	dx = cords->max_x - cords->min_x;
	dy = cords->max_y - cords->min_y;
	if (d == 1)
	{
		dx = (SFACTOR * dx) - dx;
		dy = (SFACTOR * dy) - dy;
	}
	else
	{
		dx = (1 / SFACTOR * dx) - dx;
		dy = (1 / SFACTOR * dy) - dy;
	}
	cords->min_x = cords->min_x - (dx * rx);
	cords->max_x = cords->max_x + (dx * (1 - rx));
	cords->min_y = cords->min_y - (dy * ry);
	cords->max_y = cords->max_y + (dy * (1 - ry));
}
