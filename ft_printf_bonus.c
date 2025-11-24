/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfitte <bfitte@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 07:29:56 by bfitte            #+#    #+#             */
/*   Updated: 2025/11/24 12:45:52 by bfitte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf_bonus.h"

static void	handle_type(char *c, t_flags *flags, va_list ap, int *count)
{
	char	*temp;

	if (*c == 's')
		print_s(flags, ap, count);
	else if (*c == 'c')
		print_c(flags, ap, count);
	else if (*c == 'x' || *c == 'X')
		check_hexa(flags, ap, count);
	else if (*c == 'p')
		check_hexa_p(flags, ap, count);
	else if (*c == 'd' || *c == 'i')
		print_decimal(flags, ap, count);
	else if (*c == 'u')
		print_decimal_u(flags, ap, count);
	else if (*c == '%')
		ft_putchar_fd('%', 1, count);
	else
	{
		temp = c;
		while (*temp != '%')
			temp--;
		while (*temp != *c)
			ft_putchar_fd(*temp++, 1, count);
		ft_putchar_fd(*temp, 1, count);
	}
}

static int	handle_char(char *c, t_flags *flags, int i)
{
	while (c[i] && (c[i] == '-' || c[i] == ' ' || c[i] == '0' || c[i] == '#'
			|| c[i] == '+'))
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
	while (c[i] && (c[i] >= '0' && c[i] <= '9'))
		flags->width = flags->width * 10 + (c[i++] - 48);
	if (c[i] == '.')
	{
		flags->dot = 1;
		while (c[++i] >= '0' && c[i] <= '9')
			flags->precision = flags->precision * 10 + (c[i] - 48);
	}
	flags->type = c[i];
	return (i);
}

static int	scroll_string(const char *s, va_list ap)
{
	t_flags	*flags;
	int		i;
	int		count;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1])
		{
			flags = ft_calloc(1, sizeof(t_flags));
			if (!flags)
				return (0);
			i = handle_char((char *)s, flags, ++i);
			handle_type((char *)s + i++, flags, ap, &count);
			free(flags);
		}
		else
			ft_putchar_fd(s[i++], 1, &count);
	}
	return (count);
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		count;

	if (!s)
		return (-1);
	va_start(ap, s);
	count = scroll_string(s, ap);
	va_end(ap);
	return (count);
}
