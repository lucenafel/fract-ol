/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfelipe- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 17:38:37 by lfelipe-          #+#    #+#             */
/*   Updated: 2021/10/05 16:21:44 by lfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractals.h"

void	ft_julia(t_fdata *data)
{
	ft_initalize_fdata(data);
	while (data->xx + data->yy < 4 && data->iter < 256)
	{
		data->xx = data->x0 * data->x0;
		data->yy = data->y0 * data->y0;
		data->temp = (data->x0 + data->y0) * (data->x0 + data->y0);
		data->x0 = data->xx - data->yy + data->cx;
		data->y0 = (data->temp - data->xx - data->yy) + data->cy;
		data->iter++;
	}
}
