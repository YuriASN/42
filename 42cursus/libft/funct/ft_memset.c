/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <ysantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 20:34:49 by ysantos-          #+#    #+#             */
/*   Updated: 2022/02/24 20:34:49 by ysantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The memset() function writes len bytes of value c (converted to an
unsigned char) to the string dest.	 Undefined behaviour from memset(),
resulting from storage overflow, will occur if len	is greater than	the
length of the dest	buffer.	 The behaviour is also undefined if dest is an
invalid pointer.
*/

void	*ft_memset(void *str, int c, int bytes)
{
	int	index;

	index = 0;
	while (index < bytes)
		((unsigned char *)str)[index++] = c;
	return (str);
}
