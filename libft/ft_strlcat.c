/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:52:21 by mjina             #+#    #+#             */
/*   Updated: 2023/01/16 15:47:55 by mjina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	ret;

	if ((!dest || !src) && size == 0)
		return (0);
	i = 0;
	while (*dest && i < size)
	{
		dest++;
		i++;
	}
	ret = ft_strlcpy(dest, src, size - i);
	return (ret + i);
}
