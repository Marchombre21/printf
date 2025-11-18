/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfitte <bfitte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 12:12:52 by bfitte            #+#    #+#             */
/*   Updated: 2025/11/18 14:50:25 by bfitte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libft/libft.h"
// #include "printf.h"

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

// int print_s(t_flags *flags, va_list ap)
// {
// 	char *s;
// 	int s_len;
// 	int count;

// 	s = va_arg(ap, char *);
// 	if (flags->precision && (size_t)flags->precision < ft_strlen(s))
// 		s = ft_substr(s, 0, flags->precision);
// 	s_len = ft_strlen(s);
// 	count = s_len;
// 	if (flags->minus)
// 	{
// 		ft_putstr_fd(s, 1);
// 		if (flags->width > s_len)
// 			count += print_padding(flags->width - s_len, ' ');
// 	}
// 	else
// 	{
// 		if (flags->width > s_len)
// 			count += print_padding(flags->width - s_len, ' ');
// 		ft_putstr_fd(s, 1);
// 	}
// 	return (count);
// }
