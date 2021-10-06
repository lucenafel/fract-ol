/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfelipe- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 20:43:55 by lfelipe-          #+#    #+#             */
/*   Updated: 2021/10/05 16:22:23 by lfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractals.h"

int	main(int argc, char *argv[])
{
	t_data	data;

	data.f = NULL;
	ft_parse_entry(argc, argv, &data);
	if (argc > 1 && data.f)
		ft_do_stuff(&data);
	return (0);
}
