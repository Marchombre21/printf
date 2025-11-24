/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_type_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfitte <bfitte@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 12:12:52 by bfitte            #+#    #+#             */
/*   Updated: 2025/11/24 12:46:37 by bfitte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf_bonus.h"

void	print_c(t_flags *flags, va_list ap, int *count)
{
	int	i;

	i = va_arg(ap, int);
	if (!i)
		i = 0;
	if (flags->minus)
	{
		ft_putchar_fd((char)i, 1, count);
		print_padding(flags->width - 1, flags, count, 0);
	}
	else
	{
		print_padding(flags->width - 1, flags, count, 0);
		ft_putchar_fd((char)i, 1, count);
	}
}

void	print_s(t_flags *flags, va_list ap, int *count)
{
	char	*s;
	int		s_len;
	int		malornot;

	malornot = 0;
	s = va_arg(ap, char *);
	if ((!s && !flags->dot) || (!s && flags->precision >= 6))
		s = "(null)";
	else if (!s && flags->dot && flags->precision < 6)
		s = "";
	if (flags->dot && (size_t)flags->precision < ft_strlen(s))
		s = ft_substr(s, 0, flags->precision, &malornot);
	s_len = ft_strlen(s);
	if (flags->minus)
	{
		ft_putstr_fd(s, 1, count, malornot);
		print_padding(flags->width - s_len, flags, count, 0);
	}
	else
	{
		print_padding(flags->width - s_len, flags, count, 0);
		ft_putstr_fd(s, 1, count, malornot);
	}
}

void	print_decimal(t_flags *flags, va_list ap, int *count)
{
	int		j;
	char	*s;
	int		s_len;

	j = va_arg(ap, int);
	if (!j)
		j = 0;
	s = ft_ltoa((long)j, flags);
	s_len = ft_strlen(s);
	if (j < 0)
		s_len++;
	if (flags->minus)
	{
		print_sign(flags, count, j);
		ft_putstr_fd(s, 1, count, 1);
		print_padding(flags->width - s_len, flags, count, j);
	}
	else
	{
		check_order(flags, s_len, count, j);
		ft_putstr_fd(s, 1, count, 1);
	}
}

void	print_decimal_u(t_flags *flags, va_list ap, int *count)
{
	unsigned int	i;
	char			*s;
	int				s_len;

	i = va_arg(ap, unsigned int);
	if (!i)
		i = 0;
	s = ft_ltoa((long)i, flags);
	s_len = ft_strlen(s);
	if (flags->minus)
	{
		ft_putstr_fd(s, 1, count, 1);
		print_padding(flags->width - s_len, flags, count, 0);
	}
	else
	{
		print_padding(flags->width - s_len, flags, count, 0);
		ft_putstr_fd(s, 1, count, 1);
	}
}

void	check_hexa(t_flags *flags, va_list ap, int *count)
{
	unsigned int	i;
	char			*s;
	int				s_len;

	i = va_arg(ap, unsigned int);
	if (!i)
		i = 0;
	s = ft_ltoa_hexa((unsigned long)i, flags);
	s_len = ft_strlen(s);
	if (flags->minus)
	{
		ft_putstr_fd(s, 1, count, 1);
		print_padding(flags->width - s_len, flags, count, 0);
	}
	else
	{
		if (!flags->zero || i == 0 || flags->dot)
			print_padding(flags->width - s_len, flags, count, 0);
		ft_putstr_fd(s, 1, count, 1);
	}
}
