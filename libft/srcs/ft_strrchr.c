/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 13:27:01 by tallaire          #+#    #+#             */
/*   Updated: 2021/05/31 14:48:18 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	while (*(s + i))
	{
		if (*(s + i) == c)
			tmp = ((char *)s + i);
		i++;
	}
	if (*(s + i) == c)
		tmp = ((char *)s + i);
	return (tmp);
}
