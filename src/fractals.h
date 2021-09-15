/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfelipe- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 19:53:30 by lfelipe-          #+#    #+#             */
/*   Updated: 2021/09/15 00:25:55 by lfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FRACTALS_H
#define FRACTALS_H

#include "mlx.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct s_wvdata
{
	int		i;
	int		j;
	double	temp;
	double	x0;
	double	y0;
	double	x;
	double	y;
	double	xx;
	double	yy;
}	t_wvdata;

typedef struct s_cords
{
	double	min_x;
	double	min_y;
	double	max_x;
	double	max_y;
	int		mouse_x;
	int		mouse_y;
	int		height;
	int		width;
}	t_cords;

typedef struct s_colors
{
	int	r;
	int	g;
	int	b;
	int	t;
}	t_colors;

typedef struct s_data
{
	void	*mlx;
	void	*img;
	void	*window;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		x;
	int		y;
}	t_data;

void	ft_draw_mandelbrot(t_data *data, t_cords *cords);

# endif 
