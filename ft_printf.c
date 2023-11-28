/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 19:39:19 by grebrune          #+#    #+#             */
/*   Updated: 2023/11/28 16:55:03 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str , ...)
{
	size_t	i;
	size_t	len;
	va_list	lst;

	len = 0;
	i = 0;
	va_start(lst, str);
	while (str && str[i])
	{
		if (str[i] == '%' && str[i + 1] != '\0')
		{
			len += ft_find_type(str[i + 1], lst);
			i += 2;
		}
		else
		{
			len += ft_putchar(str[i]);
			i++;
		}
	}
	va_end(lst);
	return (len);
}

//#include <stdio.h>
//
//int	main(void)
//{
////	char *str = "string";
////	char cha = 'H';
//	int	tni = 42;
//	int i = 0;
//
////	i = ft_printf("%c\n", cha);
////	ft_printf("fake=%d\n", i);
////	i = ft_printf("%c\n", cha);
////	ft_printf("reel=%d\n", i);
////
////	i = ft_printf("%s\n", str);
////	ft_printf("fake=%d\n", i);
////	i = ft_printf("%s\n", str);
////	ft_printf("reel=%d\n", i);
//
////	i = ft_printf("%p\n", (void *)str);
////	ft_printf("fake=%d\n", i);
////	i = ft_printf("%p\n", (void *)str);
////	ft_printf("reel=%d\n", i);
//
//	i = ft_printf("%d\n", tni);
//	ft_printf("fake=%d\n", i);
//	i = ft_printf("%d\n", tni);
//	ft_printf("reel=%d\n", i);
//
//	i = ft_printf("%d\n", tni);
//	ft_printf("fake=%d\n", i);
//	i = ft_printf("%d\n", tni);
//	ft_printf("reel=%d\n", i);
//	return (0);
//}
