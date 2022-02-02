/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex05C03.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 14:57:29 by marvin            #+#    #+#             */
/*   Updated: 2022/02/01 14:57:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	get_size(char *str)
{
	int	count;

	count = 0;
	while (str[count])
		++count;
	return (count);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{	
	int	index;
	int	end_dest;
	int	size_dest;
	int	size_src;

	size_dest = get_size(dest);
	size_src = get_size(src);
	index = 0;
	end_dest = size_dest + 1;
	if (size <= size_dest)
		return (size_dest + size_src);
	while (size - 1 > index && src[index])
	{
		dest[end_dest] = src[index];
		++index;
		++end_dest;
	}
	return (size_dest + size_src);
}
