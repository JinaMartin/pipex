/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 14:42:12 by mjina             #+#    #+#             */
/*   Updated: 2023/01/13 16:54:22 by mjina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	comparewhitespace(char c)
{
	if (c == '\a' || c == '\b' || c == '\f' || c == '\n' || c == '\r'
		|| c == '\t' || c == '\v' || c == ' ')
		return (1);
	return (0);
}

static int	ispositive(const char *str)
{
	int	i;
	int	pos;

	i = 0;
	pos = 1;
	while (comparewhitespace(str[i]) == 1)
		i++;
	if (str[i] == '-')
	{
		pos = -1;
		i++;
	}
	else if (str[i] == '+')
	{
		pos = 1;
		i++;
	}
	return (pos * i);
}

int	ft_atoi(const char *str)
{
	int	c;
	int	pos;
	int	ret;

	c = 0;
	ret = 0;
	pos = 1;
	if (ispositive(str) < 0)
	{
		pos = -1;
		c = ispositive(str) * -1;
	}
	else
		c = ispositive(str);
	while (str[c] >= '0' && str[c] <= '9')
	{
		ret = ret * 10 + str[c] - '0';
		c++;
	}
	ret *= pos;
	return (ret);
}
