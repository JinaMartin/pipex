/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:32:42 by mjina             #+#    #+#             */
/*   Updated: 2023/01/16 15:56:41 by mjina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t i)
{
	size_t		c;
	char		*fakesrc;
	char		*fakedest;

	if (!dest && !src && i)
		return (NULL);
	c = 0;
	fakesrc = (char *)src;
	fakedest = (char *)dest;
	while (c < i)
	{
		fakedest[c] = fakesrc[c];
		c++;
	}
	return ((char *)fakedest);
}
