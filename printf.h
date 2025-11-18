/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfitte <bfitte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 17:25:30 by bfitte            #+#    #+#             */
/*   Updated: 2025/11/18 17:48:36 by bfitte           ###   ########.fr       */
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
int print_s(t_flags *flags, va_list ap);
char	*ft_ltoa(long n, t_flags *flags);



#endif