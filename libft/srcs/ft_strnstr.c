/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 18:22:26 by tallaire          #+#    #+#             */
/*   Updated: 2021/05/31 14:48:08 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	else
	{
		while (*(haystack + i))
		{
			while (*(needle + j) == *(haystack + i + j) && i + j < len)
			{
				if (*(needle + j + 1) == '\0')
					return ((char *)haystack + i);
				j++;
			}
			j = 0;
			i++;
		}
	}
	return (NULL);
}
