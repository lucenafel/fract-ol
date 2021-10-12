/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_julia_args.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfelipe- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 16:06:12 by lfelipe-          #+#    #+#             */
/*   Updated: 2021/10/12 18:50:40 by lfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractals.h"

typedef struct s_point
{
	int	signal;
	int	dot;
	int	adot;
	int	bdot;
	int	total;
	int	check;
}	t_cpoint;

void	init_points(t_cpoint *point)
{
	point->signal = 0;
	point->dot = 0;
	point->adot = 0;
	point->bdot = 0;
	point->total = 0;
}

// checar pontos validos por meio de uma struct 
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
		point->adot++;
		str++;
	}
	if (*str == '.')
	{
		point->dot++;
		str++;
	}
	while (ft_isdigit(*str))
	{
		point->bdot++;
		str++;
	}
	if ((point->adot > 0 && point->bdot > 0) || (point->adot > 0 && point->dot == 0))
		point->total = point->signal + point->adot + point->dot + point->bdot;
	return (point->total);
}

int	ft_valid_points(char *str)
{
	size_t		i;
	int			res;
	t_cpoint	point;

	res = 0;
	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (ft_isdigit(str[i]))
		i++;
	if (str[i] == '.')
		i++;
	while (ft_isdigit(str[i]))
		i++;
	if ((size_t)ft_compare_points(str, &point) == ft_strlen(str))
		res = 1;
	return (res);
}
