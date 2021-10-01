/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfelipe- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 04:25:00 by lfelipe-          #+#    #+#             */
/*   Updated: 2021/09/28 04:55:43 by lfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractals.h"
#include "math.h"

int	ft_create_color(int iter)
{
	t_colors	color;
	double		t;

	t = (double)log(iter) / log(256.0);
	color.r = 9 * (1 - t) * t * t * t * 255;
	color.g = 15 * (1 - t) * (1 - t) * t * t * 255;
	color.b = 8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255;
	return (color.t << 24 | color.g << 16 | color.r << 8 | color.b);
}
