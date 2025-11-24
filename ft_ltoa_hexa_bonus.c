/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa_hexa_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfitte <bfitte@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 17:16:12 by bfitte            #+#    #+#             */
/*   Updated: 2025/11/24 12:45:58 by bfitte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf_bonus.h"

static int	ft_count(unsigned long i, t_flags *flags)
{
	int	j;

	j = 0;
	while (i / 16 > 0)
	{
		j++;
		i /= 16;
	}
	j++;
	while (flags->precision > j && flags->type != 'p')
		j++;
	if ((flags->diese || flags->type == 'p') && i != 0)
		j += 2;
	while (flags->width > j && flags->zero && i != 0 && !flags->dot)
		j++;
	return (j);
}

static void	ft_fill_str(char *str, unsigned long i, int nb_char, t_flags *flags)
{
	char	*base;

	ft_memset((void *)str, '0', nb_char);
	base = "0123456789abcdef";
	if (flags->type == 'X')
		base = "0123456789ABCDEF";
	if ((flags->diese || flags->type == 'p') && i != 0)
	{
		str[0] = '0';
		if (flags->type == 'X')
			str[1] = 'X';
		else
			str[1] = 'x';
	}
	while (i / 16 > 0)
	{
		str[nb_char - 1] = base[i % 16];
		i /= 16;
		nb_char--;
	}
	str[nb_char - 1] = base[i];
}

char	*ft_ltoa_hexa(unsigned long n, t_flags *flags)
{
	char	*str;
	int		nb_char;

	nb_char = ft_count(n, flags);
	if (n == 0 && flags->dot && flags->precision == 0)
	{
		str = malloc(sizeof(char) * 1);
		if (!str)
			return (NULL);
		nb_char = 0;
	}
	else
	{
		str = malloc(sizeof(char) * nb_char + 1);
		if (!str)
			return (NULL);
		ft_fill_str(str, n, nb_char, flags);
	}
	str[nb_char] = '\0';
	return (str);
}
