/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfelipe- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 19:53:30 by lfelipe-          #+#    #+#             */
/*   Updated: 2021/09/10 02:15:20 by lfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FRACTALS_H
#define FRACTALS_H

#include "mlx.h"
#include <stdlib.h>

typedef struct s_wvdata
{
	int		i;
	int		j;
	double	temp;
	double	x0;
	double	y0;
	double	x;
	double	y;
}	t_wvdata;

typedef struct s_colors
{
	int	r;
	int	g;
	int	b;
	int	t;
}	t_colors;

typedef struct s_data
{
	void	*img;
	void	*window;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

void	ft_draw_mandelbrot(t_data *data, int width, int height);

# endif 
