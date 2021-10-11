/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfelipe- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 03:54:53 by lfelipe-          #+#    #+#             */
/*   Updated: 2021/10/11 22:15:38 by lfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractals.h"

char	*ft_strtolower(char *str)
{
	char	*copy;
	int		i;

	i = 0;
	copy = (char *)malloc(ft_strlen(str) + 1);
	if (!copy)
		return (0);
	while (str[i])
	{
		copy[i] = ft_tolower(str[i]);
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

void	ft_entry_check(int argc, char **argv, char *arg, t_data *data)
{
	if (!ft_strncmp(arg, "mandelbrot", 11) && argc == 2)
		data->f = ft_mandelbrot;
	else if (!ft_strncmp(arg, "julia", 5) && argc == 4)
	{
		if (ft_valid_points(argv[2]) && ft_valid_points(argv[3]))
		{
			data->jpoint.x = ft_atof(argv[2]);
			data->jpoint.y = ft_atof(argv[3]);
			data->f = ft_julia;
		}
		else
			printf("incorrect inputs!");
	}
	else if (!ft_strncmp(arg, "burningship", 11))
		data->f = ft_draw_burning;
	else if (!ft_strncmp(arg, "tricorn", 7))
		data->f = ft_draw_tricorn;
	else
		printf("incorrect inputs!");
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
		printf("incorrect inputs!");
}
