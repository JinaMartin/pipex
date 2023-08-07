/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:14:13 by mjina             #+#    #+#             */
/*   Updated: 2023/01/10 16:22:34 by mjina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int i)
{
	if (i >= 'A' && i <= 'Z')
		return (1);
	else if (i >= 'a' && i <= 'z')
		return (1);
	return (0);
}