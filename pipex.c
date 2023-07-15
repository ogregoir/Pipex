/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogregoir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 21:00:51 by ogregoir          #+#    #+#             */
/*   Updated: 2023/06/30 18:32:07 by ogregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*get_path2(char *cmd, int i, char **gpath)
{
	char	*tpath;
	char	*path;
	int		j;

	tpath = ft_strjoin(gpath[i], "/");
	free(gpath[i]);
	gpath[i] = ft_strjoin(tpath, cmd);
	free(tpath);
	if (access(gpath[i], F_OK) == 0)
	{
		path = ft_strdup(gpath[i]);
		j = 0;
		while (gpath[j])
		{
			free(gpath[j]);
			j++;
		}
		free(gpath);
		return (path);
	}
	return (0);
}

char	*get_path(char *cmd, char **env)
{
	char	**gpath;
	char	*path;
	int		i;

	i = 0;
	if (!env)
		return (cmd);
	while (env[i] && (ft_strncmp(env[i], "PATH=", 5)))
		i++;
	if (!env[i])
	{
		ft_putstr_fd("command not found\n", 2);
		exit(EXIT_FAILURE);
	}
	gpath = ft_split(&(env[i][5]), ':');
	i = 0;
	while (gpath[i])
	{
		path = get_path2(cmd, i, gpath);
		if (path != 0)
			return (path);
		i++;
	}
	ft_putstr_fd("command not found\n", 2);
	exit(127);
}

static int	ft_error_bis(void)
{
	write(2, "not good number of arguments\n", 29);
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv, char **env)
{
	pid_t	pid;
	int		fd[2];

	if (argc != 5)
		ft_error_bis();
	else if (pipe(fd) == -1)
	{
		perror("pipe failed\n");
		return (1);
	}
	pid = fork();
	if (pid < 0)
	{
		perror("fork failed\n");
		return (2);
	}
	else if (pid == 0)
		child_process(fd, argv, env);
	else
		parent_process(fd, argv, env);
	waitpid(-1, NULL, 0);
	waitpid(-1, NULL, 0);
	return (0);
}
