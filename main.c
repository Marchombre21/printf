/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfitte <bfitte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 17:23:44 by bfitte            #+#    #+#             */
/*   Updated: 2025/11/19 18:49:00 by bfitte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdio.h>

//L'ordre des flags obligatoire : [-/0/+/ /#] ensuite [largeur] ensuite
// [precision] enfin [type]

int	main(void)
{
	// char	*s = "coucou";
	unsigned int	i = 0;
	unsigned int	j = 42;
	printf("retour de printf : %d\n", printf("Coucou %+d et truc %x\n", i, j));
	printf("retour de ft_printf : %d\n", ft_printf("Coucou %+d et truc %x\n", i, j));
	return (0);
}