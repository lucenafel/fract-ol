/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pixel_put.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfelipe- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 19:43:54 by lfelipe-          #+#    #+#             */
/*   Updated: 2021/10/15 21:42:55 by lfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractals.h"

void	ft_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(int *)dst = color;
}
