/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfelipe- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 18:31:02 by lfelipe-          #+#    #+#             */
/*   Updated: 2021/06/03 01:44:35 by lfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	intlen(int n)
{
	int	i;

	i = 0;
	while (n / 10 != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int			i;
	int			j;
	long int	ln;
	char		*str;

	j = n < 0;
	ln = n;
	if (j > 0)
		ln *= -1;
	i = intlen(n) + 1;
	str = (char *)malloc(i + j + 1);
	if (!str)
		return (NULL);
	str[i + j] = '\0';
	while (i != 0)
	{
		i--;
		str[i + j] = ln % 10 + '0';
		ln /= 10;
	}
	if (j > 0)
		str[0] = '-';
	return (str);
}
