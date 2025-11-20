/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfitte <bfitte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 08:09:48 by bfitte            #+#    #+#             */
/*   Updated: 2025/11/11 08:09:48 by bfitte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd, int *count, int mal)
{
	int	s_len;

	if (!s)
		return ;
	s_len = ft_strlen(s);
	(*count) += s_len;
	write(fd, s, s_len);
	if (mal != 0)
		free(s);
}
