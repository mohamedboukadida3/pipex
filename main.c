/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukadi <mboukadi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 23:16:43 by mboukadi          #+#    #+#             */
/*   Updated: 2023/08/11 00:00:09 by mboukadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child(int *pipefd, int *fd, char **av, char **env)
{
	char	**cmd;
	pid_t	pid1;

	pid1 = fork();
	if (pid1 == -1)
		exit(-1);
	if (pid1 == 0)
	{
		fd[0] = open(av[1], O_RDONLY, 0777);
		if (fd[0] == -1)
			exit(-1);
		cmd = ft_split(av[2], ' ');
		close(pipefd[0]);
		dup2(fd[0], STDIN_FILENO);
		dup2(pipefd[1], STDOUT_FILENO);
		if (cmd[0] && path(cmd[0], env))
		{
			execve(path(cmd[0], env), cmd, env);
			ft_free_tab(cmd);
		}
		else
			cmd_not_found(cmd);
	}
}

void	parent(int *pipefd, int *fd, char **av, char **env)
{
	char	**cmd;
	pid_t	pid2;

	pid2 = fork();
	if (pid2 == -1)
		exit(-1);
	if (pid2 == 0)
	{
		fd[1] = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
		if (fd[1] == -1)
			exit(-1);
		cmd = ft_split(av[3], ' ');
		close(pipefd[1]);
		dup2(fd[1], STDOUT_FILENO);
		dup2(pipefd[0], STDIN_FILENO);
		if (cmd[0] && path(cmd[0], env))
		{
			execve(path(cmd[0], env), cmd, env);
			ft_free_tab(cmd);
		}
		else
			cmd_not_found(cmd);
	}
}

int	main(int ac, char **av, char **env)
{
	int	pipefd[2];
	int	fd[2];

	if (ac != 5)
		write(1, "./pipex infile cmd cmd outfile\n", 32);
	if (pipe(pipefd) == -1)
		exit(-1);
	child(pipefd, fd, av, env);
	parent(pipefd, fd, av, env);
	close(pipefd[0]);
	close(pipefd[1]);
	return (0);
}
