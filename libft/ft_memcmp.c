/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:37:18 by mjina             #+#    #+#             */
/*   Updated: 2023/01/16 13:21:40 by mjina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	int				c;
	int				comp;
	unsigned char	*fakestr1;
	unsigned char	*fakestr2;

	c = 0;
	fakestr1 = (unsigned char *)str1;
	fakestr2 = (unsigned char *)str2;
	while (c < (int)n)
	{
		comp = fakestr1[c] - fakestr2[c];
		if (comp != 0)
			return (comp);
		c++;
	}
	return (0);
}
