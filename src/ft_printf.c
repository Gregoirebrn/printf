/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 19:39:19 by grebrune          #+#    #+#             */
/*   Updated: 2023/11/27 15:02:37 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/ft_printf.h"

int	ft_printf(const char *str , ...)
{
	size_t	i;
	va_list	lst;

	i = 0;
	va_start(lst, str);
	while (str && str[i])
	{
		if (str[i] == '%' && str[i + 1] != '\0')
			i += ft_find_type(str[i], lst);
		else
			ft_putchar(str[i]);
		i++;
	}
	va_end(lst);
	return (i);
}

#include <stdio.h>

int	main(void)
{
	ft_printf("%c\n", 'H');
	printf("%c\n", 'H');
	return (0);
}
