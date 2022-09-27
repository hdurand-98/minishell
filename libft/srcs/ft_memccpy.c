/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 14:44:20 by tallaire          #+#    #+#             */
/*   Updated: 2019/12/04 13:52:02 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		*buffdst;
	unsigned char		*buffsrc;

	i = 0;
	buffdst = (unsigned char *)dst;
	buffsrc = (unsigned char *)src;
	while (i < n)
	{
		*(buffdst + i) = *(buffsrc + i);
		if (*(buffdst + i) == (unsigned char)c)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
