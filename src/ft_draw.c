/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfelipe- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 02:30:59 by lfelipe-          #+#    #+#             */
/*   Updated: 2021/10/16 22:10:05 by lfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractals.h"

void	ft_window_to_world(t_fdata *data, t_cords *cords)
{
	double	sx;
	double	sy;

	sx = (double)(cords->max_x - cords->min_x) / WIDTH;
	sy = (double)(cords->max_y - cords->min_y) / HEIGHT;
	data->x0 = cords->min_x + ((double)data->i) * sx;
	data->y0 = cords->min_y + ((double)data->j) * sy;
}

void	ft_draw_fractal(t_data *data, t_cords *cords)
{
	t_fdata		fdata;

	fdata.i = 0;
	fdata.cx = data->jpoint.x;
	fdata.cy = data->jpoint.y * -1;
	while (fdata.i < WIDTH)
	{
		fdata.j = 0;
		while (fdata.j < HEIGHT)
		{
			ft_window_to_world(&fdata, cords);
			data->f(&fdata);
			ft_pixel_put(data, fdata.i, fdata.j, data->colors[fdata.iter - 1]);
			fdata.j++;
		}
		fdata.i++;
	}
	ft_push_image(data);
}

void	ft_draw_help(t_data *data)
{
	int		x;
	int		y;
	char	*dst;

	x = 0;
	while (x < 200)
	{
		y = 0;
		while (y < 600)
		{
			dst = data->addr_s + (y * data->line_length_s + x
					* (data->bits_per_pixel_s / 8));
			*(int *)dst = 0x00363636;
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(data->mlx, data->window, data->img_s, 800, 0);
	ft_print_help(data);
}
