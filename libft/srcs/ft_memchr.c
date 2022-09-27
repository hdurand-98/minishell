/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 18:13:55 by tallaire          #+#    #+#             */
/*   Updated: 2019/12/04 15:02:26 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	unsigned char		*buff;

	i = 0;
	buff = (unsigned char *)s;
	while (i < n)
	{
		if (*(buff + i) == (unsigned char)c)
			return (buff + i);
		i++;
	}
	return (NULL);
}
