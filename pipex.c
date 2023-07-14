/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 09:21:04 by mjina             #+#    #+#             */
/*   Updated: 2023/06/23 09:21:04 by mjina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[])
{
	int		p_fd[2];
	int		fd;
	pid_t	pid;
	char	*buffer;
	char	*cmd[6];

	if (pipe(p_fd) == -1)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		buffer = (char *)malloc((1024 + 1) * sizeof(char));
		if (!buffer)
		{
			exit(EXIT_FAILURE);
			return (0);
		}
		fd = open("infile.txt", O_RDONLY);
		read(fd, buffer, 18);
		close(fd);
		write(p_fd[1], buffer, 18);
		close(p_fd[0]);
		close(p_fd[1]);
		exit(EXIT_SUCCESS);
	}
	else
	{
		buffer = (char *)malloc((1024 + 1) * sizeof(char));
		if (!buffer)
		{
			exit(EXIT_FAILURE);
			return (0);
		}
		read(p_fd[0], buffer, 18);
		close(p_fd[0]);
		close(p_fd[1]);
		fd = open("outfile.txt", O_WRONLY);
		write(fd, buffer, 18);
		ft_printf("Message from child: '%s'\n", buffer);
		free(buffer);
		close(fd);
		exit(EXIT_SUCCESS);
	}

	return (0);
}
