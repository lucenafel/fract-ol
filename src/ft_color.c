/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfelipe- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 04:25:00 by lfelipe-          #+#    #+#             */
/*   Updated: 2021/10/18 19:59:41 by lfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractals.h"
#include "math.h"

void	ft_calc_colors(t_data *data)
{
	int	i;

	i = 0;
	data->colors = malloc(sizeof(int) * MAXITER);
	while (i < MAXITER)
	{
		data->colors[i] = ft_create_color(i);
		i++;
	}
}

int	ft_create_color(int iter)
{
	t_colors	color;
	double		t;

	t = (double)log(iter) / log(MAXITER);
	color.r = 9 * (1 - t) * t * t * t * 255;
	color.g = 15 * (1 - t) * (1 - t) * t * t * 255;
	color.b = 8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255;
	return (color.r << 16 | color.g << 8 | color.b);
}
