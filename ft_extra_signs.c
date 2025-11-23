/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extra_signs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfitte <bfitte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 16:24:44 by bfitte            #+#    #+#             */
/*   Updated: 2025/11/19 18:49:00 by bfitte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void	print_padding(int size, t_flags *flags, int *count)
{
	int		i;
	char	c;
	char	d;

	d = flags->type;
	if (size > 0)
	{
		if (flags->zero && (d != 'c' && d != 's' && d != 'p' && d != '%')
			&& !flags->minus && !flags->dot)
			c = '0';
		else
			c = ' ';
		i = 0;
		while (i < size)
		{
			ft_putchar_fd(c, 1, count);
			i++;
		}
	}
}

void	print_sign(t_flags *flags, int *count, int i)
{
	if (flags->space && !flags->plus && i >= 0)
		ft_putchar_fd(' ', 1, count);
	else if (flags->plus && i >= 0)
		ft_putchar_fd('+', 1, count);
	else if (i < 0)
		ft_putchar_fd('-', 1, count);
}

void	check_hexa_p(t_flags *flags, va_list ap, int *count)
{
	void			*i;
	unsigned long	j;
	char			*s;
	int				s_len;

	i = va_arg(ap, void *);
	if (!i)
		s = ft_strdup("(nil)");
	else
	{
		j = (unsigned long)i;
		s = ft_ltoa_hexa(j, flags);
	}
	s_len = ft_strlen(s);
	if (flags->minus)
	{
		ft_putstr_fd(s, 1, count, 1);
		print_padding(flags->width - s_len, flags, count);
	}
	else
	{
		print_padding(flags->width - s_len, flags, count);
		ft_putstr_fd(s, 1, count, 1);
	}
}

void	check_order(t_flags *flags, int s_len, int *count, int j)
{
	if (flags->zero && !flags->precision && !flags->dot)
	{
		print_sign(flags, count, j);
		print_padding(flags->width - s_len, flags, count);
	}
	else if (flags->zero && !flags->precision && flags->dot)
	{
		print_padding(flags->width - s_len, flags, count);
		print_sign(flags, count, j);
	}
	else
	{
		print_padding(flags->width - s_len, flags, count);
		print_sign(flags, count, j);
	}
}
