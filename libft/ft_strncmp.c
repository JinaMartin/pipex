/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 10:16:22 by mjina             #+#    #+#             */
/*   Updated: 2023/01/13 17:02:21 by mjina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t			count;
	int				comp;
	unsigned char	*fakestr1;
	unsigned char	*fakestr2;

	fakestr1 = (unsigned char *)str1;
	fakestr2 = (unsigned char *)str2;
	count = 0;
	while (str1[count] && str2[count] && count != n)
	{
		comp = fakestr1[count] - fakestr2[count];
		if (comp != 0)
			return (comp);
		count++;
	}
	if (count != n)
	{
		comp = fakestr1[count] - fakestr2[count];
		if (comp != 0)
			return (comp);
	}
	return (0);
}
