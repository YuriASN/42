/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <ysantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 15:56:29 by ysantos-          #+#    #+#             */
/*   Updated: 2022/02/27 15:56:29 by ysantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	a;
	size_t	b;

	a = ft_strlen(dst);
	b = 0;
	if (a + ft_strlen(src) > dstsize)
		return (a + ft_strlen(src));
	while (src[b] && a < dstsize)
	{
		dst[a] = src[b];
		++a;
		++b;
	}
	dst[a] = '\0';
	return (a);
}
