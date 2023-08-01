/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:10:17 by mjina             #+#    #+#             */
/*   Updated: 2023/07/19 16:10:20 by mjina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute(char *str, char **env)
{
	char	**cmd;

	cmd = ft_split(str, ' ');
	if (execve("/usr/bin/ls", cmd, env) == -1)
	{
		ft_putstr_fd("pipex: command not found: ", 2);
		ft_putendl_fd(cmd[0], 2);
		free_tab(cmd);
		exit(0);
	}
}

void	parrent(char **argv, int *p_fd, char **env)
{
	int fd;

	fd = open_file(argv[4], 1);
	dup2(fd, 1);
	dup2(p_fd[0], 0);
	close(p_fd[1]);
	execute(argv[3], env);
}

void	child(char **argv, int *p_fd, char **env)
{
	int	fd;

	fd = open_file(argv[1], 0);
	dup2(fd, 0);
	dup2(p_fd[1], 1);
	close(p_fd[0]);
	execute(argv[2], env);
}

int	main(int argc, char **argv, char **env)
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
			child(argv, p_fd, env);
		waitpid(pid, NULL, 0);
		parrent(argv, p_fd, env);
	}
	else
	{
		ft_putstr_fd("Error: Wrong arguments\n", 2);
	}
	return (0);
}
