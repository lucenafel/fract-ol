/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfelipe- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 20:43:55 by lfelipe-          #+#    #+#             */
/*   Updated: 2021/09/15 00:29:55 by lfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fractals.h"
#include <stdio.h>

int		key_hook(int key)
{
	printf("%d\n", key);
	if (key == 65307)
		exit(0);
	return (0);
}

int	get_mouse_cordinates(int key, int x, int y, t_cords *cords)
{
	if (key == 4 || key == 5)
	{
		cords->mouse_x = x;
		cords->mouse_y = y;
	}
	printf("%d, ", cords->mouse_x);
	printf("%d\n", cords->mouse_y);
	return (0);
}

int		mouse_hook(int key, int x, int y)
{
	printf("%d\n", key);
	printf("%d ,%d\n", x, y);
	return (0);
}

int		draw(int key,int x, int y, t_data *data)
{
	t_cords cords;

	cords.height = 600;
	cords.width = 800;
	if (key == 1)
	{
		ft_draw_mandelbrot(data, &cords);
	}
	if (key == 4 || key == 5)
	{
		printf("%d, %d\n", x, y);
	}
	mlx_put_image_to_window(data->mlx, data->window, data->img, 0, 0);
	return (0);
}

int		close(void)
{
	exit(0);
	return (0);
}

int	main(void)
{
	t_data	img;
	/* t_cords cords;

	cords.height = 720;
	cords.width = 1280; */

	img.mlx = mlx_init();
	img.window = mlx_new_window(img.mlx, 1280, 720, "test");
	img.img = mlx_new_image(img.mlx, 1280, 720);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	// ft_draw_mandelbrot(&img, &cords);
	mlx_mouse_hook(img.window, draw, &img);
	// mlx_put_image_to_window(img.mlx, img.window, img.img, 0, 0);
	mlx_hook(img.window, 17, 1L<<1, close, (void *)0);

	mlx_loop(img.mlx);
}
