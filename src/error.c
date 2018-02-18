
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 21:17:29 by irhett            #+#    #+#             */
/*   Updated: 2017/03/09 19:42:56 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bplus.h"

void	ft_putstr_fd(char const *s, int fd)
{
	int		len;

	if (s)
	{
		len = strlen(s);
		write(fd, s, len);
	}
}

int		ft_error(char *str)
{
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(str, 2);
	write(2, "\n", 1);
	return (1);
}
