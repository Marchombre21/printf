/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfitte <bfitte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 12:12:52 by bfitte            #+#    #+#             */
/*   Updated: 2025/11/19 18:49:00 by bfitte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

void print_c(t_flags *flags, va_list ap, int *count)
{
	int	i;
	
	i = va_arg(ap, int);
	if (flags->minus)
	{
		ft_putchar_fd((char)i, 1, count);
		print_padding(flags->width - 1, flags, count);
	}
	else
	{
		print_padding(flags->width - 1, flags, count);
		ft_putchar_fd((char)i, 1, count);
	}
}

void	print_s(t_flags *flags, va_list ap, int *count)
{
	char	*s;
	int		s_len;
	
	s = va_arg(ap, char *);
	if (flags->precision && (size_t)flags->precision < ft_strlen(s))
		s = ft_substr((char const *)s, 0, (size_t)flags->precision);
	s_len = ft_strlen(s);
	*count += s_len;
	if (flags->minus)
	{
		ft_putstr_fd(s, 1, count);
		print_padding(flags->width - s_len, flags, count);
	}
	else
	{
		print_padding(flags->width - s_len, flags, count);
		ft_putstr_fd(s, 1, count);
	}
}

void	print_decimal(t_flags *flags, va_list ap, int *count)
{
	int		j;
	char	*s;

	j = va_arg(ap, int);
	s = ft_ltoa((long)j, flags);
	if (flags->minus)
	{
		if (flags->plus && j >= 0)
			ft_putchar_fd('+', 1, count);
		else if (flags->plus && j < 0)
			ft_putchar_fd('-', 1, count);
		ft_putnbr_fd(j, 1, count);
		print_padding(flags->width - ft_strlen(s), flags, count);
	}
	else
	{
		print_padding(flags->width - ft_strlen(s), flags, count);
		if (flags->plus && j >= 0)
			ft_putchar_fd('+', 1, count);
		else if (flags->plus && j < 0)
			ft_putchar_fd('-', 1, count);
		ft_putnbr_fd(j, 1, count);
	}
	free(s);
}

void	print_decimal_u(t_flags *flags, va_list ap, int *count)
{
	unsigned int i;
	char	*s;

	i = va_arg(ap, unsigned int);
	s = ft_ltoa((long)i, flags);
	if (flags->minus)
	{
		ft_putnbr_fd(i, 1, count);
		print_padding(flags->width - ft_strlen(s), flags, count);
	}
	else
	{
		print_padding(flags->width - ft_strlen(s), flags, count);
		ft_putnbr_fd(i, 1, count);
	}
	free(s);
}

void	check_hexa(t_flags *flags, va_list ap, int *count)
{
	unsigned int	i;
	char 			*s;
	int				s_len;
	
	i = va_arg(ap, unsigned int);
	s = ft_ltoa_hexa(i, flags);
	s_len = ft_strlen(s);
	if (flags->minus)
	{
		ft_putstr_fd(s, 1, count);
		print_padding(flags->width - s_len, flags, count);
	}
	else
	{
		print_padding(flags->width - s_len, flags, count);
		ft_putstr_fd(s, 1, count);
	}
	free(s);
}
