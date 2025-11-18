/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfitte <bfitte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 17:23:44 by bfitte            #+#    #+#             */
/*   Updated: 2025/11/18 13:35:42 by bfitte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft/libft.h"
#include <stdio.h>
//L'ordre des flags obligatoire : [-/0/+/ /#] ensuite [largeur] ensuite
// [precision] enfin [type]
int	main(void)
{
	printf("Coucou %s\n", "coucou");
	ft_printf("Coucou %s\n", "coucou");
	return (0);
}