/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfelipe- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 17:16:37 by lfelipe-          #+#    #+#             */
/*   Updated: 2021/10/15 17:19:38 by lfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractals.h"

void	ft_backup_pos(t_data *data)
{
	data->reset.rmax_x = data->cords.max_x;
	data->reset.rmax_y = data->cords.max_y;
	data->reset.rmin_x = data->cords.min_x;
	data->reset.rmin_y = data->cords.min_y;
}

void	ft_reset_pos(t_data *data)
{
	data->cords.max_x = data->reset.rmax_x;
	data->cords.max_y = data->reset.rmax_y;
	data->cords.min_x = data->reset.rmin_x;
	data->cords.min_y = data->reset.rmin_y;
}
