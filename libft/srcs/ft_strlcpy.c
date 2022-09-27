/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 14:44:52 by tallaire          #+#    #+#             */
/*   Updated: 2019/12/09 14:27:22 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (!dst || !src)
		return (0);
	while (*(src + i) && dstsize > 1)
	{
		*(dst + i) = *(src + i);
		dstsize--;
		i++;
	}
	if (dstsize > 0)
		*(dst + i) = '\0';
	while (*(src + i))
		i++;
	return (i);
}
