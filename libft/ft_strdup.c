/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfelipe- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 23:35:22 by lfelipe-          #+#    #+#             */
/*   Updated: 2021/05/29 00:02:04 by lfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*ptr;
	size_t	s_len;

	s_len = ft_strlen(s) + 1;
	ptr = malloc(s_len);
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s, s_len);
	return (ptr);
}
