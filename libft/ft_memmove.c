/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:37:48 by mjina             #+#    #+#             */
/*   Updated: 2023/01/16 15:55:19 by mjina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t i)
{
	int		c;

	if (!src && !dest)
		return (0);
	if (src < dest)
	{
		while (i > 0)
		{
			((char *)dest)[i - 1] = ((char *)src)[i - 1];
			i--;
		}
	}
	else
	{
		c = 0;
		while ((size_t)c < i)
		{
			((char *)dest)[c] = ((char *)src)[c];
			c++;
		}
	}
	return (dest);
}
