/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 16:48:24 by tallaire          #+#    #+#             */
/*   Updated: 2019/12/11 13:05:11 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*buffdst;
	unsigned char		*buffsrc;

	i = 0;
	buffdst = (unsigned char *)dst;
	buffsrc = (unsigned char *)src;
	if (src == dst)
		return (dst);
	if (buffsrc < buffdst)
	{
		while (++i <= n)
			*(buffdst + (n - i)) = *(buffsrc + (n - i));
	}
	else
		ft_memcpy(dst, src, n);
	return (dst);
}
