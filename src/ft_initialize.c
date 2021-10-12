/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfelipe- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 17:05:34 by lfelipe-          #+#    #+#             */
/*   Updated: 2021/10/12 18:41:10 by lfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractals.h"

void	ft_mlx_initialize(t_data *data)
{
	data->mlx = mlx_init();
	data->window = mlx_new_window(data->mlx, WIDTH, HEIGHT, "fractal");
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
}

void	ft_coords_initialize(t_data *data)
{
	if (data->type == 'm')
	{
		data->cords.max_x = 1.0;
		data->cords.min_x = -2.5;
		data->cords.max_y = 1.1;
		data->cords.min_y = -1.1;
	}
	if (data->type == 'j')
	{
		data->cords.max_x = 2.0;
		data->cords.min_x = -2.0;
		data->cords.max_y = 2.0;
		data->cords.min_y = -2.0;
	}
	if (data->type == 'b')
	{
		data->cords.max_x = 1.5;
		data->cords.min_x = -2.5;
		data->cords.max_y = 1.0;
		data->cords.min_y = -2.0;
	}
}

int	ft_push_image(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->window, data->img, 0, 0);
	return (0);
}

void	ft_initalize_fdata(t_fdata *fdata)
{
	fdata->x = 0;
	fdata->y = 0;
	fdata->xx = 0;
	fdata->yy = 0;
	fdata->temp = 0;
	fdata->iter = 0;
}
