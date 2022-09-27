/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 12:01:21 by tallaire          #+#    #+#             */
/*   Updated: 2019/12/11 12:38:26 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** Calcule la longueur necessaire de la chaine de caracteres renvoyée par
** la fonction *ft_itoa().
**
** renvoie le nombre de caractere sans compter le '\0'.
*/

static	int	ft_len(int n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	size_t	len;
	size_t	sign;
	char	*str;

	len = ft_len(n);
	sign = 0;
	if (n < 0)
		sign++;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	*(str + len) = '\0';
	while (len)
	{
		len--;
		if (n < 0)
			*(str + len) = ((n % 10) * (-1)) + '0';
		else
			*(str + len) = (n % 10) + '0';
		n /= 10;
	}
	if (sign)
		*(str + len) = '-';
	return (str);
}
