/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_burning_ship.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfelipe- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 02:05:57 by lfelipe-          #+#    #+#             */
/*   Updated: 2021/10/06 02:15:05 by lfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractals.h"

void	ft_draw_burning(t_fdata *data)
{
	ft_initalize_fdata(data);
	data->xx = data->x0;
	data->yy = data->y0;
	while (data->xx * data->xx + data->yy * data->yy < 4 && data->iter < 256)
	{
		data->temp = data->xx * data->xx - data->yy * data->yy + data->x0;
		data->yy = fabs(2 * data->xx * data->yy) + data->y0;
		data->xx = data->temp;
		data->iter++;
	}
}
