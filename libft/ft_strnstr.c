/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 10:29:44 by mjina             #+#    #+#             */
/*   Updated: 2023/01/16 15:10:48 by mjina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *small, size_t len)
{
	size_t	bigc;
	size_t	smallc;

	bigc = 0;
	if (!*small)
		return ((char *)big);
	if (len == 0)
		return (NULL);
	while (bigc <= len && big[bigc] && len > 0)
	{
		smallc = 0;
		while (small[smallc] && (big[bigc + smallc] == small[smallc])
			&& bigc + smallc < len)
			smallc++;
		if (small[smallc] == 0)
			return (&((char *)big)[bigc]);
		bigc++;
	}
	return (NULL);
}
