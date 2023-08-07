/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:31:34 by mjina             #+#    #+#             */
/*   Updated: 2023/01/13 14:02:26 by mjina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	c;

	if (!dest || !src)
		return (0);
	c = 0;
	while (c + 1 < size && src[c] != '\0')
	{
		dest[c] = src[c];
		c++;
	}
	if (c != size)
		dest[c] = '\0';
	return (ft_strlen(src));
}
