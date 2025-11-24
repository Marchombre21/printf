/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfitte <bfitte@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 17:16:12 by bfitte            #+#    #+#             */
/*   Updated: 2025/11/24 12:46:09 by bfitte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf_bonus.h"

static int	ft_count(long n, t_flags *flags)
{
	int	i;
	int	div;

	i = 1;
	div = 1;
	while (n / div > 9)
	{
		i++;
		div *= 10;
	}
	while (flags->precision > i)
		i++;
	return (i);
}

static void	ft_fill_str(char *str, long nb, int nb_char)
{
	char	c;

	ft_memset((void *)str, '0', nb_char);
	if (nb > 9)
	{
		c = (nb % 10) + 48;
		str[nb_char - 1] = c;
		ft_fill_str(str, nb / 10, nb_char - 1);
	}
	else
	{
		c = nb + 48;
		str[nb_char - 1] = c;
	}
}

char	*ft_ltoa(long n, t_flags *flags)
{
	char	*str;
	int		nb_char;

	if (n < 0)
		n = -n;
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
		ft_fill_str(str, n, nb_char);
	}
	str[nb_char] = '\0';
	return (str);
}
