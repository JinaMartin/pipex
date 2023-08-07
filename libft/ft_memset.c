/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:49:26 by mjina             #+#    #+#             */
/*   Updated: 2023/01/13 14:40:55 by mjina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memset(void *str, int c, size_t n)
{
	size_t	count;
	char	*ptr;

	count = 0;
	ptr = str;
	if (!str)
		return (0);
	while (count < n)
	{
		ptr[count] = c;
		count++;
	}
	return (str);
}
