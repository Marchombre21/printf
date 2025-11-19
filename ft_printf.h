/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfitte <bfitte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 17:25:30 by bfitte            #+#    #+#             */
/*   Updated: 2025/11/19 16:28:26 by bfitte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

#include <stdarg.h>

typedef struct s_flags
{
	int	minus;
	int	zero;
	int	precision;
	int	diese;
	int	plus;
	int	space;
	int	width;
	char type;
}	t_flags;

int	ft_printf(const char *s, ...);
void print_s(t_flags *flags, va_list ap, int *count);
char	*ft_ltoa(long n, t_flags *flags);
char	*ft_ltoa_hexa(unsigned int n, t_flags *flags);
void print_padding(int size, t_flags *flags, int *count);
void print_c(t_flags *flags, va_list ap, int *count);
void	print_s(t_flags *flags, va_list ap, int *count);
void	print_decimal(t_flags *flags, va_list ap, int *count);
void	print_decimal_u(t_flags *flags, va_list ap, int *count);
void	check_hexa(t_flags *flags, va_list ap, int *count);



#endif