/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfelipe- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 15:25:19 by lfelipe-          #+#    #+#             */
/*   Updated: 2021/09/25 11:24:04 by lfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractals.h"

void	ft_initalize_fdata(t_fdata *fdata)
{
	fdata->x = 0;
	fdata->y = 0;
	fdata->xx = 0;
	fdata->yy = 0;
	fdata->temp = 0;
	fdata->iter = 0;
}

void	ft_mandelbrot(t_fdata *data)
{
	ft_initalize_fdata(data);
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
