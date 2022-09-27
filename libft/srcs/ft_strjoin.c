/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 16:33:18 by tallaire          #+#    #+#             */
/*   Updated: 2021/05/31 14:42:42 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	lens1;
	unsigned int	lens2;
	int				i;
	char			*join;

	lens1 = 0;
	lens2 = 0;
	i = -1;
	if (!s1 || !s2)
		return (NULL);
	while (*(s1 + lens1))
		lens1++;
	while (*(s2 + lens2))
		lens2++;
	join = (char *)malloc((lens1 + lens2) + 1);
	if (!join)
		return (NULL);
	while (*(s1 + ++i))
		*(join + i) = *(s1 + i);
	i = -1;
	while (*(s2 + ++i))
		*(join + lens1 + i) = *(s2 + i);
	*(join + lens1 + i) = '\0';
	return (join);
}
