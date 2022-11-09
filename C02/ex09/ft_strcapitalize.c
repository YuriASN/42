/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <ysantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 22:49:48 by ysantos-          #+#    #+#             */
/*   Updated: 2022/01/31 20:45:01 by ysantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcapitalize(char *str)
{
	int	index;

	index = 0;
	if (*str > 96 && *str < 123)
	{
		*str -= 32;
	}
	while (*str)
	{
		if (*(str - 1) < '0' || (*(str - 1) > '9' && *(str - 1) < 'A')
			|| (*(str - 1) > 'Z' && *(str - 1) < 'a') || *(str - 1) > 'z')
		{
			if (*str >= 'a' && *str <= 'z')
				*str -= 32;
		}
		else if (*(str - 1) >= '0' || (*(str - 1) <= '9' && *(str - 1) >= 'A')
			|| (*(str - 1) <= 'Z' && *(str - 1) >= 'a') || *(str - 1) <= 'z')
		{
			if (*str >= 'A' && *str <= 'Z')
				*str += 32;
		}
		++str;
		++index;
	}
	return (str -= index);
}

/* int main(void)
{
	char word0[] = "salut comment tu vas ? 42mots quarante-deux";
	// char word0[] = " vas # 42mots";
	printf("\n\nBefore:\n%s\n", word0);
	printf("\nAfter:\n%s\n\n\n", ft_strcapitalize(word0));

	char word1[] = "sAlUt coMMent TU vas ? 42mots QUArante-deux";
	printf("\nBefore:\n%s\n", word1);
	printf("\nAfter:\n%s\n\n\n", ft_strcapitalize(word1));

	char word2[] = "#alut comment tu vas ? 42mots quarante-deux";
	printf("\nBefore:\n%s\n", word2);
	printf("\nAfter:\n%s\n\n\n", ft_strcapitalize(word2));

	char word3[] = "5alut comment tu vas ? 42mots quarante-deux";
	printf("\nBefore:\n%s\n", word3);
	printf("\nAfter:\n%s\n\n\n", ft_strcapitalize(word3));
} */