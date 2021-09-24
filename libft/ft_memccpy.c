/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfelipe- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 12:13:33 by lfelipe-          #+#    #+#             */
/*   Updated: 2021/06/10 21:01:19 by lfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t	i;

	if (!dest && !src)
		return (NULL);
	i = 0;
	while (i < n)
	{
		if (*(unsigned char *)(src + i) == (unsigned char)c)
		{
			*(unsigned char *)(dest + i) = *(unsigned char *)(src + i);
			return (dest + i + 1);
		}
		*(unsigned char *)(dest + i) = *(unsigned char *)(src + i);
		i++;
	}
	return (NULL);
}
