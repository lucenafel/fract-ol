/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfelipe- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 17:05:34 by lfelipe-          #+#    #+#             */
/*   Updated: 2021/09/25 11:08:28 by lfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractals.h"

void	ft_mlx_initialize(t_data *data)
{
	data->mlx = mlx_init();
	data->window = mlx_new_window(data->mlx, 800, 600, "fractals");
	data->img = mlx_new_image(data->mlx, 800, 600);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			 &data->line_length, &data->endian);
}

void	ft_coords_initialize(t_cords *cords)
{
	cords->width = 800;
	cords->height = 600;
	cords->max_x = 2.0;
	cords->min_x = -2.0;
	cords->max_y = 2.0;
	cords->min_y = -2.0;
}

void	ft_push_image(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->window, data->img, 0, 0);
}
