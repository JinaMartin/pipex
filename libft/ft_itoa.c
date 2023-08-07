/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:46:05 by mjina             #+#    #+#             */
/*   Updated: 2023/01/25 11:46:06 by mjina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	intlen(int n)
{
	int		i;
	int		ispos;

	ispos = 1;
	i = 0;
	if (n < 0)
		ispos = -1;
	while (n >= 10 || n <= -10)
	{
		n /= 10;
		i++;
	}
	if (ispos == -1)
		i++;
	i++;
	return (i);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*str;

	i = intlen(n);
	if (n == 0)
		return (str = ft_strdup("0"));
	if (n == -2147483648)
		return (str = ft_strdup("-2147483648"));
	str = (char *)malloc((i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[intlen(n)] = '\0';
	if (n < 0)
		n *= -1;
	
	while (n > 0)
	{
		str[i - 1] = n % 10 + '0';
		n /= 10;
		i--;
	}
	if (i == 1)
		str[0] = '-';
	return (str);
}
