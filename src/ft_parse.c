/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfelipe- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 03:54:53 by lfelipe-          #+#    #+#             */
/*   Updated: 2021/10/01 17:28:38 by lfelipe-         ###   ########.fr       */
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

void	ft_entry_check(char **args, t_data *data)
{
	if (!ft_strncmp(args[0], "mandelbrot", 11))
		data->f = ft_mandelbrot;
	else if (!ft_strncmp(args[0], "julia", 5))
	{
		data->f = ft_julia;
		while (args)
		{
			printf("%s\n", *args);
			args++;
		}
	}
	else
		printf("incorrect inputs!");
}

void	ft_parse_entry(int argc, char **argv, t_data *data)
{
	char	**copy;
	int		i;

	i = 1;
	copy = (char **)malloc(sizeof(char **) * (argc - 1));
	if (argc == 1)
		printf("Incorrect inputs!");
	else
	{
		while (i < argc)
		{
			copy[i - 1] = ft_strtolower(*(argv + i));
			i++;
		}
		ft_entry_check(copy, data);
	}
	ft_args_free(copy, argc - 1);
}
