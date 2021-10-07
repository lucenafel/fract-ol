/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfelipe- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 02:30:59 by lfelipe-          #+#    #+#             */
/*   Updated: 2021/10/06 02:02:00 by lfelipe-         ###   ########.fr       */
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
	fdata.cx = data->jpoint.x;
	fdata.cy = data->jpoint.y;
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

int	ft_put_cordinade(int key, int x, int y)
{
	printf("key :%d ->%d, %d\n", key, x, y);
	return (0);
}

int	ft_get_key(int key); // temp

void	ft_do_stuff(t_data *data)
{
	ft_coords_initialize(&data->cords);
	ft_mlx_initialize(data);
	ft_draw_fractal(data, &data->cords);
	mlx_hook(data->window, 17, 1L << 0, ft_free, data);
	mlx_hook(data->window, 06, 1L << 6, ft_put_cordinade, (void *)0);
	mlx_mouse_hook(data->window, ft_mouse_hook, data);
	mlx_key_hook(data->window, ft_get_key, data);
	mlx_loop(data->mlx);
}
