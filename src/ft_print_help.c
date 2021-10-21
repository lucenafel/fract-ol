/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_help.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfelipe- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 21:26:36 by lfelipe-          #+#    #+#             */
/*   Updated: 2021/10/17 20:23:58 by lfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractals.h"

void	ft_print_help(t_data *data)
{
	mlx_string_put(data->mlx, data->window, 810,
		30, 0x00FFFFFF, "Welcome to fractal render");
	mlx_string_put(data->mlx, data->window, 810, 60,
		0x00FFFFFF, "Zoom in with ->SCROLLUP");
	mlx_string_put(data->mlx, data->window, 810, 90,
		0x00FFFFFF, "Zoom out with ->SCROLLDOWN");
	mlx_string_put(data->mlx, data->window, 810, 120,
		0x00FFFFFF, "Arrows to move the image");
	mlx_string_put(data->mlx, data->window, 810, 150,
		0x00FFFFFF, "R to reset the image");
	mlx_string_put(data->mlx, data->window, 810, 210,
		0x00FFFFFF, "ESC to quite the program");
	mlx_string_put(data->mlx, data->window, 810, 590,
		0x00FFFFFF, "Made By BDRS CODE!");
}
