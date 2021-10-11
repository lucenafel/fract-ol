/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tricorn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfelipe- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 01:03:08 by lfelipe-          #+#    #+#             */
/*   Updated: 2021/10/11 23:34:45 by lfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractals.h"

void	ft_draw_tricorn(t_fdata *data)
{
	ft_initalize_fdata(data);
	data->x = data->x0;
	data->y = data->y0;
	data->xx = data->x;
	data->yy = data->y;
	while (data->xx * data->xx + data->yy + data->yy < 4 && data->iter < MAXITER)
	{
		data->temp = data->xx * data->xx - data->yy * data->yy + data->x;
		data->yy = -2 * data->xx * data->yy + data->y;
		data->xx = data->temp;
		data->iter++;
	}
}
