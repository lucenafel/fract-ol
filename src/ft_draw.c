/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfelipe- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 02:30:59 by lfelipe-          #+#    #+#             */
/*   Updated: 2021/10/12 02:30:07 by lfelipe-         ###   ########.fr       */
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

void	ft_test(t_data *data, t_cords *cords)
{
	double	sx;
	double	sy;

	sx = (double)(cords->max_x - cords->min_x) / WIDTH;
	sy = (double)(cords->max_y - cords->min_y) / HEIGHT;
	data->jpoint.x = cords->min_x + ((double)data->mouse_x) * sx;
	data->jpoint.y = cords->min_y + ((double)data->mouse_y) * sy;
}

void	ft_draw_fractal(t_data *data, t_cords *cords)
{
	t_fdata		fdata;

	fdata.i = 0;
	fdata.cx = data->jpoint.x;
	fdata.cy = data->jpoint.y;
	while (fdata.i < WIDTH)
	{
		fdata.j = 0;
		while (fdata.j < HEIGHT)
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
	ft_coords_initialize(data);
	ft_mlx_initialize(data);
	ft_draw_fractal(data, &data->cords);
	mlx_hook(data->window, 17, 1L << 0, ft_free, data);
	// mlx_hook(data->window, 06, 1L << 6, ft_put_cordinade, data);
	mlx_expose_hook(data->window, ft_push_image, data);
	mlx_mouse_hook(data->window, ft_mouse_hook, data);
	mlx_key_hook(data->window, ft_key_hook, data);
	mlx_loop(data->mlx);
}
