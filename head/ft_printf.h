/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 19:25:27 by grebrune          #+#    #+#             */
/*   Updated: 2023/11/28 15:58:15 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

int	ft_printf(const char *str, ...);
ssize_t	ft_find_type(const char c, va_list lst);
ssize_t	ft_putnbr_b(ssize_t i, char *base, ssize_t *parse);
ssize_t	ft_putnbr_addr(size_t i, char *base, ssize_t *parse);
size_t	ft_putstr(char *str);
int	ft_putchar(char c);

#endif
