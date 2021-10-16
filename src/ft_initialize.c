/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfelipe- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 17:05:34 by lfelipe-          #+#    #+#             */
/*   Updated: 2021/10/16 22:50:32 by lfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractals.h"

void	ft_mlx_initialize(t_data *data)
{
	data->mlx = mlx_init();
	data->window = mlx_new_window(data->mlx, 1000, HEIGHT, "fractal");
	data->img_s = mlx_new_image(data->mlx, 200, 600);
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	data->addr_s = mlx_get_data_addr(data->img_s, &data->bits_per_pixel_s,
			&data->line_length_s, &data->endian_s);
}

static void	ft_coords_2(t_data *data)
{
	if (data->type == 't')
	{
		data->cords.max_x = 1.5;
		data->cords.min_x = -2.0;
		data->cords.max_y = 1.5;
		data->cords.min_y = -1.5;
	}
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
	else if (data->type == 'j')
	{
		data->cords.max_x = 2.0;
		data->cords.min_x = -2.0;
		data->cords.max_y = 2.0;
		data->cords.min_y = -2.0;
	}
	else if (data->type == 'b')
	{
		data->cords.max_x = 1.5;
		data->cords.min_x = -2.5;
		data->cords.max_y = 1.0;
		data->cords.min_y = -2.0;
	}
	else
		ft_coords_2(data);
}

int	ft_push_image(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->window, data->img, 0, 0);
	mlx_put_image_to_window(data->mlx, data->window, data->img_s, 800, 0);
	ft_print_help(data);
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
