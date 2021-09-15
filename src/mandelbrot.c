/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfelipe- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 15:25:19 by lfelipe-          #+#    #+#             */
/*   Updated: 2021/09/15 00:12:16 by lfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractals.h"
#include <math.h>

int		create_color(int iter)
{
	t_colors	color;
	double		t;

	t = (double)iter/256.0;
	color.r = 9 * (1 - t) * t * t * t * 255;
	color.g = 15 * (1 - t) * (1 - t) * t * t * 255;
	color.b = 8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255;
	return (color.t << 24 | color.r << 16 | color.g << 8 | color.b);
}

void	my_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	// printf("%d, %d\n", x, y);
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(int *)dst = color;
}

void	ft_window_view_to_world(t_wvdata *data, t_cords *cords)
{
	data->x0 = 3.0 / cords->width * data->i - 2.0;
	data->y0 = 2.2 / cords->height * data->j - 1.1;
}

void	ft_draw_mandelbrot(t_data *data, t_cords *cords)
{
	t_wvdata	mdata;
	int			iter;

	mdata.i = 0;
	while (mdata.i < cords->width)
	{
		mdata.j = 0;
		while (mdata.j < cords->height)
		{
			ft_window_view_to_world(&mdata, cords);
			iter = 0;
			mdata.x = 0;
			mdata.y = 0;
			mdata.xx = 0;
			mdata.yy = 0;
			mdata.temp = 0;
			while (mdata.x * mdata.x + mdata.y * mdata.y < 4 && iter < 256)
			{
				mdata.x = mdata.xx - mdata.yy + mdata.x0;
				mdata.y = (mdata.temp - mdata.xx - mdata.yy) + mdata.y0;
				mdata.xx = mdata.x * mdata.x;
				mdata.yy = mdata.y * mdata.y;
				mdata.temp = (mdata.x + mdata.y) * (mdata.x + mdata.y);
				iter++;
			}
			my_pixel_put(data, mdata.i, mdata.j, create_color(iter));
			mdata.j++;
			}
		mdata.i++;
	}
}
