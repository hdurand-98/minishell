/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 15:38:59 by tallaire          #+#    #+#             */
/*   Updated: 2021/05/31 14:42:56 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*d;
	const char	*s;
	size_t		dlen;

	d = dst;
	s = src;
	while (size != 0 && *d != '\0')
	{
		--size;
		++d;
	}
	dlen = d - dst;
	if (size == 0)
		return (dlen + ft_strlen(s));
	while (*s != '\0')
	{
		if (size != 1)
		{
			*d++ = *s;
			--size;
		}
		++s;
	}
	*d = '\0';
	return (dlen + (s - src));
}
