/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 20:20:56 by ysantos-          #+#    #+#             */
/*   Updated: 2022/01/27 02:58:25 by ysantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_numbers(void)
{
	int	nbr;

	nbr = '0';
	while (nbr <= '9')
	{
		write (1, &nbr, 1);
		++nbr;
	}
}

/*int	main(void)
{
	ft_print_numbers();
	return (0);
}*/
