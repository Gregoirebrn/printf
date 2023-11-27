/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 18:03:16 by grebrune          #+#    #+#             */
/*   Updated: 2023/11/27 15:13:21 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

size_t	ft_putstr(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_find_type(void *c, va_list lst)
{
	ssize_t	i;

	i = 0;
	if (c == 'c')
		i = ft_putchar((unsigned char)va_arg(lst, int));
	else if (c == 's')
		i = ft_putstr(va_arg(lst, char *));
	else if (c == 'p')
	{
		i = ft_putstr("0x");
		if (i < - 1)
			return (i);
		ft_putnbr_addr((size_t)(lst, size_t), unsigned int, "0123456789abcdef", &i);
	}
	else if (c == 'd' || c == 'i')
		ft_putnbr_b(va_arg(lst, int), "0123456789", &i);
	else if (c == 'u')
		ft_putnbr_b(va_arg(lst, unsigned int), "0123456789", &i);
	else if (c == 'x')
		ft_putnbr_b(va_arg(lst, unsigned int), "0123456789abcdef", &i);
	else if (c == 'X')
		ft_putnbr_b(va_arg(lst, unsigned int), "0123456789ABCDEF", &i);
	if (c == '%')
		i += ft_putchar('%');
	return (i);
}
