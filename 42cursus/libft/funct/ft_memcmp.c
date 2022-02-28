/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <ysantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 14:53:25 by ysantos-          #+#    #+#             */
/*   Updated: 2022/02/27 14:53:25 by ysantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	int	index;

	index = 0;
	while (index < n)
	{
		if (((unsigned char *)str1)[index] != ((unsigned char *)str2)[index])
			return (((char *)str1)[index] - ((char *)str2)[index]);
		++index;
	}
	return (0);
}
