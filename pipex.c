/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 16:56:23 by mjina             #+#    #+#             */
/*   Updated: 2023/08/01 16:56:28 by mjina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parrent(char **argv, int *p_fd, char **envp)
{
	int	fd;

	fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd == -1)
		exit(1);
	dup2(p_fd[0], STDIN_FILENO);//0);
	dup2(fd, STDOUT_FILENO);//1);
	close(p_fd[1]);
	execute(argv[3], envp);
}

void	child(char **argv, int *p_fd, char **envp)
{
	int	fd;

	fd = open(argv[1], O_RDONLY, 0777);
	if (fd == -1)
		exit(1);
	dup2(p_fd[1], STDOUT_FILENO);//1);
	dup2(fd, STDIN_FILENO);//0);
	close(p_fd[0]);
	execute(argv[2], envp);
}

int	main(int argc, char **argv, char **envp)
{
	int		p_fd[2];
	pid_t	pid;

	if (argc == 5)
	{
		if (pipe(p_fd) == -1)
			exit(-1);
		pid = fork();
		if (pid == -1)
			exit(-1);
		if (pid == 0)
			child(argv, p_fd, envp);
		waitpid(pid, NULL, 0);
		parrent(argv, p_fd, envp);
	}
	else
	{
		ft_putstr_fd("Error: Incorrect arguments\n", 2);
	}
	return (0);
}
