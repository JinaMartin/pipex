/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 11:54:55 by mjina             #+#    #+#             */
/*   Updated: 2023/02/03 11:54:55 by mjina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*list;
	t_list	*temp;

	if (lst && *lst && del)
	{
		list = *lst;
		while (list)
		{
			temp = list->next;
			ft_lstdelone(list, del);
			list = temp;
		}
		*lst = NULL;
	}
}
