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

void	*ft_memset(void *str, int c, int bytes)
{
	int	index;

	index = 0;
	while (index < bytes)
		((unsigned char *)str)[index++] = c;
	return (str);
}
