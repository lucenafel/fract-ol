/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfelipe- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 19:53:30 by lfelipe-          #+#    #+#             */
/*   Updated: 2021/10/12 00:53:34 by lfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTALS_H
# define FRACTALS_H

# include "mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "libft.h"

# define K_LEFT 65361
# define K_RIGHT 65363
# define K_UP 65362
# define K_DOWN 65364
# define SFACTOR 1.05
# define MAXITER 256
# define WIDTH 800
# define HEIGHT 600

typedef struct s_fdata
{
	int		i;
	int		j;
	int		iter;
	double	temp;
	double	x0;
	double	y0;
	double	x;
	double	y;
	double	xx;
	double	yy;
	double	cx;
	double	cy;
}	t_fdata;

typedef struct s_jpoint
{
	double	x;
	double	y;
}	t_jpoint;

typedef struct s_cords
{
	double	min_x;
	double	min_y;
	double	max_x;
	double	max_y;
	double	cx;
	double	cy;
	int		mouse_x;
	int		mouse_y;
	int		width;
	int		height;
}	t_cords;

typedef struct s_data
{
	void		*mlx;
	void		*img;
	void		*window;
	char		*addr;
	void		(*f)(t_fdata *);
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			mouse_x;
	int			mouse_y;
	t_jpoint	jpoint;
	t_cords		cords;
}	t_data;

typedef struct s_colors {
	int	r;
	int	g;
	int	b;
	int	t;
}	t_colors;

void	ft_draw_fractal(t_data *data, t_cords *coords);
void	ft_mlx_initialize(t_data *data);
int		ft_push_image(t_data *data);
void	ft_coords_initialize(t_cords *cords);
void	ft_parse_entry(int argc, char **argv, t_data *data);
void	my_pixel_put(t_data *data, int x, int y, int color);
void	ft_mandelbrot(t_fdata *data);
int		ft_create_color(int iter);
void	ft_do_stuff(t_data *data);
void	ft_julia(t_fdata *data);
int		ft_free(t_data *data);
void	ft_coords_initialize(t_cords *cords);
void	ft_initalize_fdata(t_fdata *fdata);
int		ft_free(t_data *data);
void	ft_args_free(char **args, int nargs);
int		ft_valid_points(char *str);
void	ft_zoom_in(int d, int x, int y, t_cords *cords);
int		ft_mouse_hook(int key, int x, int y, t_data *data);
void	ft_draw_burning(t_fdata *data);
void	ft_draw_tricorn(t_fdata *data);

#endif
