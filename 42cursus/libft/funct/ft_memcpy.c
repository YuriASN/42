/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <ysantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 15:24:10 by ysantos-          #+#    #+#             */
/*   Updated: 2022/03/30 00:22:04 by ysantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Copies n characters from memory area src to memory area dest.
This function returns a pointer to destination, which is dest. */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!src && !dest)
		return (0);
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		++i;
	}
	((unsigned char *)dest)[i] = '\0';
	return (dest);
}

/* int	main(void)
{
	const char	src[] = "https://profile.intra.42.fr/";
	char		dest[50] = "Heloooo!!";

	printf("Before memcpy dest = %s\n", dest);
	ft_memcpy(dest, src, ft_strlen(src)+1);
	printf("After memcpy dest = %s\n", dest);
	return (0);
} */
