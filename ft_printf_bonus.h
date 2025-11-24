/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfitte <bfitte@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 17:25:30 by bfitte            #+#    #+#             */
/*   Updated: 2025/11/24 12:48:09 by bfitte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>

typedef struct s_flags
{
	int		minus;
	int		zero;
	int		dot;
	int		precision;
	int		diese;
	int		plus;
	int		space;
	int		width;
	char	type;
}	t_flags;

int		ft_printf(const char *s, ...)__attribute__((format(printf, 1, 2)));
void	print_s(t_flags *flags, va_list ap, int *count);
char	*ft_ltoa(long n, t_flags *flags);
char	*ft_ltoa_hexa(unsigned long n, t_flags *flags);
void	print_padding(int size, t_flags *flags, int *count, int j);
void	print_c(t_flags *flags, va_list ap, int *count);
void	print_s(t_flags *flags, va_list ap, int *count);
void	print_decimal(t_flags *flags, va_list ap, int *count);
void	print_decimal_u(t_flags *flags, va_list ap, int *count);
void	check_hexa(t_flags *flags, va_list ap, int *count);
void	print_sign(t_flags *flags, int *count, int i);
void	check_hexa_p(t_flags *flags, va_list ap, int *count);
void	check_order(t_flags *flags, int s_len, int *count, int j);

#endif