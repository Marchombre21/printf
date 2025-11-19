/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa_hexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfitte <bfitte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 17:16:12 by bfitte            #+#    #+#             */
/*   Updated: 2025/11/19 18:49:09 by bfitte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

static int	ft_count(unsigned int i, t_flags *flags)
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
	if (flags->diese || flags->type == 'p')
		j += 2;
	return (j);
}

static void	ft_fill_str(char *str, unsigned int i, int nb_char, t_flags *flags)
{
	char	*base;
	
	base = "0123456789abcdef";
	if (flags->type == 'X')
		base = "0123456789ABCDEF";
	if (flags->diese || flags->type == 'p')
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

char	*ft_ltoa_hexa(unsigned int n, t_flags *flags)
{
	char	*str;
	int		nb_char;

	nb_char = ft_count(n, flags);
	str = ft_calloc(nb_char + 1, sizeof(char));
	
	if (!str)
		return (NULL);
	ft_fill_str(str, n, nb_char, flags);
	return (str);
}
