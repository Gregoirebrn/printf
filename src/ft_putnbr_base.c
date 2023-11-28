/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:25:25 by grebrune          #+#    #+#             */
/*   Updated: 2023/11/28 16:15:52 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/ft_printf.h"

size_t	ft_strlen(char *str)
{
	int	i;
	int	x;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '+' || str[i] == '-')
			return (-1);
		x = -1;
		while (str[++x])
			if (str[i] == str[x] && x != i)
				return (-1);
	}
	return (i);
}

int	ft_putchar_base(unsigned int nbr, char *base, unsigned int len, ssize_t *parse)
{
	if (nbr < len)
	{
		if (-1 == write(1, &base[nbr], 1))
			return (-1);
		*parse += 1;
	}
	else
	{
		ft_putchar_base(nbr / len, base, len, parse);
		ft_putchar_base(nbr % len, base, len, parse);
	}
	return (0);
}

ssize_t	ft_putnbr_b(ssize_t nbr, char *base, ssize_t *parse)
{
	size_t	len;

	len = ft_strlen(base);
	if (len <= 1)
		return (0);
	if (nbr < 0)
	{
		if ( -1 == write(1, "-", 1))
			return (-1);
		*parse += 1;
		if (-1 == ft_putchar_base(nbr * -1, base, len, parse))
			return (-1);
	}
	else
		ft_putchar_base(nbr, base, len, parse);
	return (*parse);
}

ssize_t	ft_putnbr_addr(size_t nbr, char *base, ssize_t *parse)
{
//	if (!(char *)nbr)
//	{
//		parse += ft_putstr("(nil)");
//		return (parse);
//	}
	if (nbr < ft_strlen(base))
	{
		if (-1 == write(1, &base[nbr], 1))
			return (*parse);
		*parse += 1;
//		{
//			parse = -1;
//			return (parse);
//		}
//		else
	}
	else
	{
		ft_putnbr_addr(nbr / ft_strlen(base), base, parse);
		ft_putnbr_addr(nbr % ft_strlen(base), base, parse);
	}
	return (*parse);
}
