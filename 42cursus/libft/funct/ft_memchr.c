/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <ysantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 22:31:43 by ysantos-          #+#    #+#             */
/*   Updated: 2022/02/24 22:31:43 by ysantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memchr(const void *str, int c, size_t bytes)
{
	int	index;

	index = 0;
	while (index < bytes && ((unsigned char *)str)[index] != '\0')
	{
		if (((unsigned char *)str)[index] == (unsigned char)c)
			return ((void *)(str + index));
		index++;
	}
	return (0);
}
