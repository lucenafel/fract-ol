/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfelipe- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 01:02:15 by lfelipe-          #+#    #+#             */
/*   Updated: 2021/05/29 01:14:14 by lfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		i;
	char	numbers[10];

	i = 0;
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	if (n == 0)
		ft_putchar_fd('0', fd);
	else if (n < 0 && n != -2147483648)
	{
		n *= -1;
		ft_putchar_fd('-', fd);
	}
	while (n > 0)
	{
		numbers[i] = (n % 10) + '0';
		n /= 10;
		i++;
	}
	i--;
	while (i >= 0)
	{
		ft_putchar_fd(numbers[i], fd);
		i--;
	}
}
