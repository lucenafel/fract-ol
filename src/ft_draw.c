/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfelipe- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 02:30:59 by lfelipe-          #+#    #+#             */
/*   Updated: 2021/09/24 06:12:02 by lfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractals.h"

void	ft_window_to_world(t_fdata *data, t_cords *cords)
{
	double	sx;
	double	sy;

	sx = (double)(cords->max_x - cords->min_x) / cords->width;
	sy = (double)(cords->max_y - cords->min_y) / cords->height;
	data->x0 = cords->min_x + ((double)data->i) * sx;
	data->y0 = cords->min_y + ((double)data->j) * sy;
}

void	ft_draw_fractal(t_data *data, t_cords *cords)
{
	t_fdata		fdata;

	fdata.i = 0;
	while (fdata.i < cords->width)
	{
		fdata.j = 0;
		while (fdata.j < cords->height)
		{
			ft_window_to_world(&fdata, cords);
			data->f(&fdata);
			my_pixel_put(data, fdata.i, fdata.j, ft_create_color(fdata.iter));
			fdata.j++;
		}
		fdata.i++;
	}
	ft_push_image(data);
}

void	ft_do_stuff(t_data *data)
{
	t_cords cords;

	ft_coords_initialize(&cords);
	ft_mlx_initialize(data);
	ft_draw_fractal(data, &cords);
	mlx_hook(data->window, 17, 1L<<0, ft_free, data);
	mlx_loop(data->mlx);
}
