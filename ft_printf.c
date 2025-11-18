/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfitte <bfitte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 07:29:56 by bfitte            #+#    #+#             */
/*   Updated: 2025/11/18 18:17:49 by bfitte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "printf.h"
#include <stdio.h>

static int print_padding(int size, t_flags *flags)
{
	int i;
	char	c;
	char	d;
	
	d = flags->type;
	if (size > 0)
	{
		if (flags->zero && (d != 'c' || d != 's' || d != 'p' || d != '%')
				 && !flags->minus)
			c = '0';
		else
			c = ' ';
		i = 0;
		while (i < size)
		{
			ft_putchar_fd(c, 1);
			i++;
		}

	}
	return (size);
}

// static int print_padding(int size, char c)
// {
// 	int i;

// 	i = 0;
// 	while (i < size)
// 	{
// 		ft_putchar_fd(c, 1);
// 		i++;
// 	}
// 	return (size);
// }

int print_c(t_flags *flags, va_list ap)
{
	int	i;
	int		count;
	
	count = 1;
	i = va_arg(ap, int);
	if (flags->minus)
	{
		ft_putchar_fd((char)i, 1);
		count += print_padding(flags->width - 1, flags);
	}
	else
	{
		count += print_padding(flags->width - 1, flags);
		ft_putchar_fd((char)i, 1);
	}
	return (count);
}

int	print_s(t_flags *flags, va_list ap)
{
	char	*s;
	int		s_len;
	int		count;
	
	s = va_arg(ap, char *);
	if (flags->precision && (size_t)flags->precision < ft_strlen(s))
		s = ft_substr((char const *)s, 0, (size_t)flags->precision);
	s_len = ft_strlen(s);
	count = s_len;
	if (flags->minus)
	{
		ft_putstr_fd(s, 1);
		count += print_padding(flags->width - s_len, flags);
	}
	else
	{
		count += print_padding(flags->width - s_len, flags);
		ft_putstr_fd(s, 1);
	}
	return (count);
}

int	print_decimal(t_flags *flags, va_list ap)
{
	int		count;
	int		j;
	char	*s;

	j = va_arg(ap, int);
	s = ft_ltoa((long)j, flags);
	if (flags->minus)
	{
		ft_putnbr_fd(j, 1);
		count = print_padding(flags->width - ft_strlen(s), flags);
	}
	else
	{
		count = print_padding(flags->width - ft_strlen(s), flags);
		ft_putnbr_fd(j, 1);
	}
	return (count);
}

// int	print_decimal_u(t_flags *flags, va_list ap)
// {
// 	unsigned int i;
// 	int	count;

// 	i = va_arg(ap, unsigned int);
// 	count = count_numbers((long)i);
// 	while (i > 9)
// 	{
// 		ft_putchar_fd((i % 10) + 48, 1);
// 		i /= 10;
// 	}
// 	ft_putchar_fd(i + 48, 1);
// 	return (count);
// }

static void handle_type(char c, t_flags *flags, va_list ap)
{
	if (c == 's')
		print_s(flags, ap);
	else if (c == 'c')
		print_c(flags, ap);
	// else if (c == 'p' || c == 'x' || c == 'X')
	// 	print_hexa(flags, ap);
	else if (c == 'd' || c == 'i')
		print_decimal(flags, ap);
	// else if (c == 'u')
	// 	print_decimal_u(flags, ap);
	// else if (c == '%')
	// 	ft_putchar_fd('%', 1);
	else
	{
		ft_putchar_fd('%', 1);
		ft_putchar_fd(c, 1);
	}
}

static int handle_char(char *c, t_flags *flags, int i)
{
	while (c[i] == '-' || c[i] == ' ' || c[i] == '0' || c[i] == '#' 
			|| c[i] == '+')
	{
		if (c[i] == '-')
			flags->minus = 1;
		else if (c[i] == ' ')
			flags->space = 1;
		else if (c[i] == '0')
			flags->zero = 1;
		else if (c[i] == '#')
			flags->diese = 1;
		else if (c[i] == '+')
			flags->plus = 1;
		i++;
	}
	while (c[i] >= '0' && c[i] <= '9')
		flags->width = flags->width * 10 + (c[i++] - 48);
	if (c[i] == '.')
		while (c[++i] >= '0' && c[i] <= '9')
			flags->precision = flags->precision * 10 + (c[i] - 48);
	flags->type = c[i];
	return (i);
}

int ft_printf(const char *s, ...)
{
	va_list ap;
	t_flags *flags;
	int i;
	// char	flags[8];

	i = 0;
	va_start(ap, s);
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1])
		{
			flags = ft_calloc(1, sizeof(t_flags));
			if (!flags)
				return (0);
			i++;
			i = handle_char((char *)s, flags, i);
			handle_type(s[i++], flags, ap);
		}
		else
			ft_putchar_fd(s[i++], 1);
	}
	va_end(ap);
	return (0);
}

int	main(void)
{
	printf("Coucou %03d et truc\n", 8);
	ft_printf("Coucou %03d et truc\n", 8);
	return (0);
}