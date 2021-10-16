/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfelipe- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 03:22:39 by lfelipe-          #+#    #+#             */
/*   Updated: 2021/10/15 21:27:37 by lfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractals.h"

int	ft_free(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	mlx_clear_window(data->mlx, data->window);
	mlx_destroy_window(data->mlx, data->window);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free(data->colors);
	exit(0);
	return (0);
}
