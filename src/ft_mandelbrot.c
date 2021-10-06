/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfelipe- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 15:25:19 by lfelipe-          #+#    #+#             */
/*   Updated: 2021/10/05 23:52:52 by lfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractals.h"

static int	ft_bounded_points(double x, double y)
{
	double	tmp;
	int		i;

	i = 0;
	tmp = (x - 0.25) * (x - 0.25) + y * y;
	if ((x + 1.0) * (x + 1.0) + y * y < 0.0625
		|| tmp * (tmp + (x - 0.25)) < 0.25 * y * y
		|| (((x + 0.125) * (x + 0.125)) + (y - 0.744) * (y - 0.744)) < 0.0088
		|| (((x + 0.125) * (x + 0.125)) + (y + 0.744) * (y + 0.744)) < 0.0088)
	{
		i = 256;
	}
	return (i);
}

void	ft_mandelbrot(t_fdata *data)
{
	ft_initalize_fdata(data);
	data->iter = ft_bounded_points(data->x0, data->y0);
	while (data->xx + data->yy < 4 && data->iter < 256)
	{
		data->x = data->xx - data->yy + data->x0;
		data->y = (data->temp - data->xx - data->yy) + data->y0;
		data->xx = data->x * data->x;
		data->yy = data->y * data->y;
		data->temp = (data->x + data->y) * (data->x + data->y);
		data->iter++;
	}
}
