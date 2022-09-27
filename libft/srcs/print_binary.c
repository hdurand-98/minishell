/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_binary.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 14:58:31 by tallaire          #+#    #+#             */
/*   Updated: 2021/05/31 14:59:18 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/libft.h"

static	void	print_char(char value, int nb_octet)
{
	int	i;

	i = (nb_octet * 8) - 1;
	while (i >= 0)
	{
		ft_putnbr_fd((value >> i) & 1, 1);
		ft_putchar_fd(' ', 1);
		--i;
		if ((i + 1) % 8 == 0)
			ft_putchar_fd('\n', 1);
	}
}

static	void	print_int(int value, int nb_octet)
{
	int	i;

	i = (nb_octet * 8) - 1;
	while (i >= 0)
	{
		ft_putnbr_fd((value >> i) & 1, 1);
		ft_putchar_fd(' ', 1);
		--i;
		if ((i + 1) % 8 == 0)
			ft_putchar_fd('\n', 1);
	}
}

static	void	print_long_long_int(long long int value, int nb_octet)
{
	int	i;

	i = (nb_octet * 8) - 1;
	while (i >= 0)
	{
		ft_putnbr_fd((value >> i) & 1, 1);
		ft_putchar_fd(' ', 1);
		--i;
		if ((i + 1) % 8 == 0)
			ft_putchar_fd('\n', 1);
	}
}

void	print_binary(long long int value, int nb_octet)
{
	if (nb_octet == 1)
		return (print_char(value, nb_octet));
	if (nb_octet == 4)
		return (print_int(value, nb_octet));
	if (nb_octet == 8)
		return (print_long_long_int(value, nb_octet));
}
