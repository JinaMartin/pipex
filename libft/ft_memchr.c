/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:19:44 by mjina             #+#    #+#             */
/*   Updated: 2023/01/16 14:52:27 by mjina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdio.h>

void	*ft_memchr(const void *str, int c, size_t n)
{
	const char	*fakestr;
	size_t		count;

	if (n == 0)
		return (NULL);
	fakestr = str;
	count = 0;
	while (*fakestr != (char)c && count < n - 1)
	{
		fakestr++;
		count++;
	}
	if (*fakestr == (char)c)
		return ((char *)fakestr);
	return (NULL);
}
