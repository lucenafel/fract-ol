/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfelipe- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 19:14:35 by lfelipe-          #+#    #+#             */
/*   Updated: 2021/10/12 19:40:35 by lfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	calcpow(int base, int expo)
{
	int	res;
	int	i;

	i = 1;
	res = base;
	while (i < expo)
	{
		res *= base;
		i++;
	}
	return (res);
}

static void	conver_f(t_atof *var, char *str)
{
	var->bdot = 0;
	var->adot = 0;
	while (*str >= '0' && *str <= '9')
	{
		var->bdot = (var->bdot * 10) + (*str - '0');
		str++;
	}
	if (*str == '.')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		var->adot = (var->adot * 10) + (*str - '0');
		var->count++;
		str++;
	}
}

double	ft_atof(char *str)
{
	t_atof	var;

	var.signal = 1;
	var.count = 0;
	var.res = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
	{
		var.signal = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	conver_f(&var, str);
	var.res = var.bdot + (var.adot / calcpow(10, var.count));
	return (var.res * var.signal);
}
