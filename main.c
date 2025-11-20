/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfitte <bfitte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 17:23:44 by bfitte            #+#    #+#             */
/*   Updated: 2025/11/20 17:59:22 by bfitte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdio.h>

//L'ordre des flags obligatoire : [-/0/+/ /#] ensuite [largeur] ensuite
// [precision] enfin [type]

int	main(void)
{
	int	ncm_p;

	ncm_p = 1;
	printf("retour de printf : %d\n", printf(" %u ", -9));
	printf("retour de ft_printf : %d\n", ft_printf(" %u ", -9));
	printf("retour de printf : %d\n", printf(" %u ", INT_MIN));
	printf("retour de ft_printf : %d\n", ft_printf(" %u ", INT_MIN));
	printf("retour de printf : %d\n", printf(" %u ", LONG_MAX));
	printf("retour de ft_printf : %d\n", ft_printf(" %u ", LONG_MAX));
	printf("retour de printf : %d\n", printf(" %u ", UINT_MAX));
	printf("retour de ft_printf : %d\n", ft_printf(" %u ", UINT_MAX));
	printf("retour de printf : %d\n", printf(" %u ", ULONG_MAX));
	printf("retour de ft_printf : %d\n", ft_printf(" %u ", ULONG_MAX));
	return (0);
}
