/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_stuff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfelipe- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 19:29:23 by lfelipe-          #+#    #+#             */
/*   Updated: 2021/10/16 20:23:43 by lfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractals.h"

void	ft_do_stuff(t_data *data)
{
	ft_coords_initialize(data);
	ft_backup_pos(data);
	ft_calc_colors(data);
	ft_mlx_initialize(data);
	ft_draw_fractal(data, &data->cords);
	ft_draw_help(data);
	mlx_hook(data->window, 17, 1L << 0, ft_free, data);
	// mlx_hook(data->window, 06, 1L << 6, ft_put_cordinade, data);
	mlx_expose_hook(data->window, ft_push_image, data);
	mlx_mouse_hook(data->window, ft_mouse_hook, data);
	mlx_key_hook(data->window, ft_key_hook, data);
	mlx_loop(data->mlx);
}
