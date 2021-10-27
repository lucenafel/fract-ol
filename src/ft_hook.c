/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfelipe- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 03:49:46 by lfelipe-          #+#    #+#             */
/*   Updated: 2021/10/26 14:41:01 by lfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractals.h"

int	ft_mouse_hook(int key, int x, int y, t_data *data)
{
	if (key == SCROLLUP && x < 800)
		ft_zoom(1, x, y, &data->cords);
	if (key == SCROLLDOWN && x < 800)
		ft_zoom(-1, x, y, &data->cords);
	ft_draw_fractal(data, &data->cords);
	return (0);
}

static void	ft_move(int key, t_data *data, double dx, double dy)
{
	if (key == K_LEFT)
	{
		data->cords.max_x += dx * 0.05;
		data->cords.min_x += dx * 0.05;
	}
	else if (key == K_RIGHT)
	{
		data->cords.max_x -= dx * 0.05;
		data->cords.min_x -= dx * 0.05;
	}
	else if (key == K_UP)
	{
		data->cords.max_y += dy * 0.05;
		data->cords.min_y += dy * 0.05;
	}
	else
	{
		data->cords.max_y -= dy * 0.05;
		data->cords.min_y -= dy * 0.05;
	}
	ft_draw_fractal(data, &data->cords);
}

int	ft_key_hook(int key, t_data *data)
{
	double	dx;
	double	dy;

	dx = (data->cords.max_x - data->cords.min_x);
	dy = (data->cords.max_y - data->cords.min_y);
	if (key == K_ESC)
		ft_free(data);
	if (key == K_R)
	{
		ft_reset_pos(data);
		ft_draw_fractal(data, &data->cords);
	}
	if (key == K_LEFT || key == K_RIGHT || key == K_UP || key == K_DOWN)
		ft_move(key, data, dx, dy);
	return (0);
}
