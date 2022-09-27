/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/04 14:44:50 by tallaire          #+#    #+#             */
/*   Updated: 2020/04/04 14:44:51 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static	size_t	ft_len(int n, int base)
{
	size_t	len;

	len = 0;
	if (n <= 0)
		++len;
	while (n)
	{
		n /= base;
		++len;
	}
	return (len);
}

static	char	*ft_strcpy_stat(char *dst, char const *src)
{
	int	i;

	i = 0;
	while (src && dst && src[i])
	{
		dst[i] = src[i];
		++i;
	}
	dst[i] = '\0';
	return (dst);
}

/*
** before it was :
** while (len)
** {
**    len--
*/

char	*ft_itoa_base(int n, int base)
{
	size_t	len;
	size_t	sign;
	char	*str;
	char	index[16];

	len = ft_len(n, base);
	sign = 0;
	ft_strcpy_stat(index, "0123456789abcdef");
	if (n < 0)
		++sign;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		if (n < 0)
			str[len] = index[((n % base) * (-1))];
		else
			str[len] = index[(n % base)];
		n /= base;
	}
	if (sign)
		str[len] = '-';
	return (str);
}
