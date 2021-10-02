/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_julia_args.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfelipe- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 16:06:12 by lfelipe-          #+#    #+#             */
/*   Updated: 2021/10/02 04:08:25 by lfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractals.h"

void	ft_check_julia(char **args)
{
	int i;

	i = 0;
	if (*args[i] == '+' || *args[i] == '-')
		i++;
	while (!ft_isdigit(*args[i]))
		i++;
	if (*args[i] == '.')
		i++;
	while (!ft_isdigit(*args[i]))
		i++;
}
