/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfelipe- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 20:43:55 by lfelipe-          #+#    #+#             */
/*   Updated: 2021/10/01 10:57:09 by lfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractals.h"

int	main(int argc, char *argv[])
{
	t_data	data;

	ft_parse_entry(argc, argv, &data);
	/* if (argc > 1)
		ft_do_stuff(&data); */
	return (0);
}
