/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfelipe- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 18:52:58 by lfelipe-          #+#    #+#             */
/*   Updated: 2021/10/21 01:13:21 by lfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractals.h"

void	ft_error(void)
{
	printf("\033[1;31m");
	printf("[INVALID INPUTS]\n");
	printf("avaliable fractals are : mandelbrot, julia ,burningship\
 and tricorn\n");
	printf("eg : ./fractal \"fractal name\"\n");
	printf("julia requires aditional inputs\n");
	printf("eg : ./fractal julia \"real\" \"imaginary\"\n");
	printf("     ./fractal julia -0.4 -0.6\n");
	printf("\033[0;36m");
	printf("offered by BDRS CODE!\n");
}
