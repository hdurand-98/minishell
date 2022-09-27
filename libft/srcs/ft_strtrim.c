/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 17:49:36 by tallaire          #+#    #+#             */
/*   Updated: 2021/05/31 14:50:24 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** Vérifie si le charactère [c] passé en paramettre est égale à
** l'un des charactères de la chaine de charactère [*set].
**
** renvoie (1) si :
** - oui.
** renvoie (0) si :
** non.
*/

size_t	ft_is_set(const char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

/*
** Alloue avec malloc() une copie [*str] de la chaine de charactère [*s1]
** passée en paramettre en supprimant au début et à la fin de la chaine [*s1]
** les charactères présents dans la chaine de charactère [*set]
** passée en paramettre.
**
** Renvoie ([str]) si :
** - l'allocation avec malloc() de [str] n'échoue pas.
**
** sinon renvoie (NULL).
*/

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	len;
	size_t	i;
	char	*str;

	i = 0;
	if (!s1 || !set)
		return (NULL);
	while (ft_is_set(*s1, set))
		s1++;
	len = ft_strlen(s1);
	while (len && ft_is_set(*(s1 + (--len)), set))
		;
	str = (char *)malloc(sizeof(char) * (len + 2));
	if (!str)
		return (NULL);
	while (i <= len)
	{
		*(str + i) = *(s1 + i);
		i++;
	}
	*(str + i) = '\0';
	return (str);
}
