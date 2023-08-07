/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:06:22 by mjina             #+#    #+#             */
/*   Updated: 2023/01/10 17:08:00 by mjina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_bzero(void *str, size_t i)
{
	char	*s;
	size_t	c;

	c = 0;
	s = (char *)str;
	while (c < i)
	{
		s[c] = 0;
		c++;
	}
}