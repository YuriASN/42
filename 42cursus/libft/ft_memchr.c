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

void *memchr(const void *str, int c, size_t bytes)
{
	int	index;

	while (index < bytes && ((const char *)str)[index] != c)
		index++;

		
}