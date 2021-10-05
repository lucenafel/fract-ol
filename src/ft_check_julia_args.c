/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_julia_args.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfelipe- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 16:06:12 by lfelipe-          #+#    #+#             */
/*   Updated: 2021/10/04 17:55:50 by lfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractals.h"

int	ft_valid_points(char *str)
{
	int	i;
	int	res;

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
	if (i == ft_strlen(str))
		res = 1;
	return (res);
}
