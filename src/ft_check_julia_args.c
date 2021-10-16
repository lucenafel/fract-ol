/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_julia_args.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfelipe- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 16:06:12 by lfelipe-          #+#    #+#             */
/*   Updated: 2021/10/16 19:04:05 by lfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractals.h"

void	init_points(t_cpoint *point)
{
	point->signal = 0;
	point->dot = 0;
	point->adot = 0;
	point->bdot = 0;
	point->total = 0;
}

int	ft_compare_points(char *str, t_cpoint *point)
{
	init_points(point);
	if (*str == '+' || *str == '-')
	{
		point->signal++;
		str++;
	}
	while (ft_isdigit(*str))
	{
		point->bdot++;
		str++;
	}
	if (*str == '.')
	{
		point->dot++;
		str++;
	}
	while (ft_isdigit(*str))
	{
		point->adot++;
		str++;
	}
	if ((point->bdot > 0 && point->adot > 0)
		|| (point->bdot > 0 && point->dot == 0))
		point->total = point->signal + point->adot + point->dot + point->bdot;
	return (point->total);
}

int	ft_valid_points(char *str)
{
	t_cpoint	point;

	return ((size_t)ft_compare_points(str, &point) == ft_strlen(str));
}
