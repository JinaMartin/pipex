/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:10:39 by mjina             #+#    #+#             */
/*   Updated: 2023/07/19 16:10:42 by mjina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int open_file(char *file, int rd_wr)
{
    int ret;

    if (rd_wr == 0)
    {
        ret = open(file, O_RDONLY);
    }
    else if (rd_wr == 1)
    {
        ret = open(file, O_WRONLY);
    }
    else
        ret = -1;
    return (ret);
}

void    free_tab(char **str)
{
    int i;

    i = -1;
    while (str[++i])
    {
        free(str[i]);
    }
    exit(0);
}
