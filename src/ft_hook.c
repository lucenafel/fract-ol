/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfelipe- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 03:49:46 by lfelipe-          #+#    #+#             */
/*   Updated: 2021/10/05 22:03:01 by lfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractals.h"

int	ft_mouse_hook(int key, int x, int y, t_data *data)
{
	if (key == 5)
		ft_zoom_in(1, x, y, &data->cords);
	if (key == 4)
		ft_zoom_in(-1, x, y, &data->cords);
	ft_draw_fractal(data, &data->cords);
	return (0);
}

int	ft_get_key(int key, t_data *data)
{
	if (key == 65307)
		ft_free(data);
	if (key == K_LEFT)
	{
		data->cords.max_x /= 1.05;
		data->cords.min_x -= -data->cords.max_x;
	}
	if (key == K_RIGHT)
	{
		data->cords.min_x *= 1.05;
		data->cords.max_x += data->cords.min_x;
	}
	if (key == K_UP)
	{
		data->cords.max_y /= 1.05;
		data->cords.min_y -= -data->cords.max_y;
	}
	if (key == K_DOWN)
	{
		data->cords.max_y *= 1.05;
		data->cords.min_y += data->cords.max_y;
	}
	ft_draw_fractal(data, &data->cords);
	return (0);
}
