/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_padding.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfitte <bfitte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 16:24:44 by bfitte            #+#    #+#             */
/*   Updated: 2025/11/19 18:49:00 by bfitte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void print_padding(int size, t_flags *flags, int *count)
{
	int		i;
	char	c;
	char	d;
	
	d = flags->type;
	if (size > 0)
	{
		if (flags->zero && (d != 'c' || d != 's' || d != 'p' || d != '%')
				 && !flags->minus && !flags->precision)
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