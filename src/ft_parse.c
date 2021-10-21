/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfelipe- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 03:54:53 by lfelipe-          #+#    #+#             */
/*   Updated: 2021/10/18 18:53:42 by lfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractals.h"

void	ft_entry_check2(int argc, char *arg, t_data *data)
{
	if (!ft_strncmp(arg, "burningship", 11) && argc == 2)
	{
		data->f = ft_draw_burning;
		data->type = 'b';
	}
	else if (!ft_strncmp(arg, "tricorn", 7) && argc == 2)
	{
		data->f = ft_draw_tricorn;
		data->type = 't';
	}
	else
		ft_error();
}

void	ft_entry_check(int argc, char **argv, char *arg, t_data *data)
{
	if (!ft_strncmp(arg, "mandelbrot", 11) && argc == 2)
	{
		data->f = ft_mandelbrot;
		data->type = 'm';
	}
	else if (!ft_strncmp(arg, "julia", 5) && argc == 4)
	{
		if (ft_valid_points(argv[2]) && ft_valid_points(argv[3]))
		{
			data->jpoint.x = ft_atof(argv[2]);
			data->jpoint.y = ft_atof(argv[3]);
			data->f = ft_julia;
			data->type = 'j';
		}
		else
			ft_error();
	}
	else
		ft_entry_check2(argc, arg, data);
}

void	ft_parse_entry(int argc, char **argv, t_data *data)
{
	char	*copy;

	if (argv[1] && argc > 1)
	{
		copy = ft_strtolower(argv[1]);
		ft_entry_check(argc, argv, copy, data);
		free(copy);
	}
	else
		ft_error();
}
