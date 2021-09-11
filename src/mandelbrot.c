/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfelipe- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 15:25:19 by lfelipe-          #+#    #+#             */
/*   Updated: 2021/09/11 01:49:29 by lfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractals.h"
#include <math.h>

int		create_color(int iter)
{
	t_colors	color;
	double		t;
	double		max_iter;

	max_iter = 1024.0;
	t = (double)iter/max_iter;
	color.r = 9 * (1 - t) * t * t * t * 255;
	color.g = 15 * (1 - t) * (1 - t) * t * t * 255;
	color.b = 8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255;
	return (color.t << 24 | color.r << 16 | color.g << 8 | color.b);
}

void	my_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(int *)dst = color;
}

void	ft_window_view_to_world(t_wvdata *data, int width, int height)
{
	data->x0 = 3.0 / width * data->i - 2.0;
	data->y0 = 2.2 / height * data->j - 1.1;
}

void	ft_draw_mandelbrot(t_data *data, int width, int height)
{
	t_wvdata	mdata;
	int			iter;

	mdata.i = 0;
	while (mdata.i < width)
	{
		mdata.j = 0;
		while (mdata.j < height)
		{
			ft_window_view_to_world(&mdata, width, height);
			iter = 0;
			mdata.x = 0;
			mdata.y = 0;
			while (mdata.x * mdata.x + mdata.y * mdata.y < 4 && iter < 1024)
			{
				mdata.temp = mdata.x * mdata.x - mdata.y * mdata.y + mdata.x0;
				mdata.y = 2 * mdata.x * mdata.y + mdata.y0;
				mdata.x = mdata.temp;
				iter++;
			}
			my_pixel_put(data, mdata.i, mdata.j, create_color(iter));
			mdata.j++;
		}
	mdata.i++;
	}
}
