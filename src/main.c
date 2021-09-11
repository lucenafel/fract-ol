/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfelipe- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 20:43:55 by lfelipe-          #+#    #+#             */
/*   Updated: 2021/09/10 23:02:10 by lfelipe-         ###   ########.fr       */
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

int		mouse_hook(int key, int x, int y)
{
	printf("%d\n", key);
	printf("%d ,%d\n", x, y);
	return (0);
}

int		close(void)
{
	exit(0);
	return (0);
}

int	main(void)
{
	void	*mlx;
	t_data	img;

	mlx = mlx_init();
	img.window = mlx_new_window(mlx, 1280, 720, "test");
	img.img = mlx_new_image(mlx, 1280, 720);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	ft_draw_mandelbrot(&img, 1280, 720);
	mlx_key_hook(img.window, key_hook, &img);
	mlx_mouse_hook(img.window, mouse_hook, (void *)0);
	mlx_put_image_to_window(mlx, img.window, img.img, 0, 0);
	mlx_destroy_image(mlx, img.img);
	mlx_hook(img.window, 17, 1L<<1, close, (void *)0);

	mlx_loop(mlx);
}
