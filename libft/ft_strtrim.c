/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:22:58 by mjina             #+#    #+#             */
/*   Updated: 2023/01/17 16:23:00 by mjina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	checkback(char const *s1, char const *set)
{
	int	i;
	int	shuffle;

	i = ft_strlen(s1);
	while (i >= 0)
	{
		shuffle = ft_strlen(set);
		while (s1[i] != set[shuffle] && shuffle >= 0)
			shuffle--;
		if (s1[i] == set[shuffle])
			i--;
		else if (shuffle < 0)
			break ;
	}
	i++;
	return (i);
}

static int	fronttrim(char const *s1, char const *set)
{
	int	i;
	int	shuffle;

	i = 0;
	while (s1[i])
	{
		shuffle = ft_strlen(set) - 1;
		while (s1[i] != set[shuffle] && shuffle >= 0)
			shuffle--;
		if (s1[i] == set[shuffle])
			i++;
		else if (shuffle < 0)
			break ;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		back;
	int		front;

	if (!s1 || !set)
	{
		return (NULL);
	}
	front = fronttrim(s1, set);
	if ((size_t)front == ft_strlen(s1))
	{
		str = (char *)ft_calloc(1, sizeof(char));
		return (str);
	}
	back = ft_strlen(s1) - checkback(s1, set) - 1;
	str = (char *)malloc((ft_strlen(s1) - front - back) * sizeof(char));
	ft_strlcpy(str, s1 + front, ft_strlen(s1) - front - back);
	return (str);
}
