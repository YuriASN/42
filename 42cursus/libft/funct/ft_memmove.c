/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <ysantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 15:49:41 by ysantos-          #+#    #+#             */
/*   Updated: 2022/03/13 21:28:16 by ysantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*tmp;

	tmp = (char *)malloc(sizeof(char) * n);
	i = 0;
	while (i < n && ((unsigned char *)src)[i])
	{
		tmp[i] = ((unsigned char *)src)[i];
		++i;
	}
	tmp[i] = '\0';
	i = 0;
	while (i < n && tmp[i])
	{
		((char *)dest)[i] = tmp[i];
		++i;
	}
	((char *)dest)[i] = '\0';
	free (tmp);
	return (dest);
}

/* int	main(void)
{
	char str1[50] = "I am going from Delhi to Gorakhpur";
	char str2[50] = "I am going from Delhi to Gorakhpur";
//Use of memmove
	printf("Function:\tft_memmove with overlap\n");
	printf("Orignal :\t%s\n",str1);
	printf("Source:\t\t%s\n", str1 + 5);
	printf("Destination:\t%s\n", str1 + 11);
	ft_memmove(str1 + 11, str1 + 5, 29);
	printf("Result:\t\t%s\n", str1);
	printf("Length:\t\t%ld characters\n\n", ft_strlen(str1));
//Use of ft_memcpy
	printf("Function:\tft_memcpy with overlap\n" );
	printf("Orignal :\t%s\n",str2);
	printf("Source:\t\t%s\n", str2 + 5);
	printf("Destination:\t%s\n", str2 + 11);
	ft_memcpy(str2 + 11, str2 + 5, 29);
	printf("Result:\t\t%s\n", str2);
	printf("Length:\t\t%ld characters\n\n", ft_strlen(str2));
	return (0);
} */
