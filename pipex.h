/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogregoir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 21:01:06 by ogregoir          #+#    #+#             */
/*   Updated: 2023/06/26 12:31:07 by ogregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft/libft.h"

int		child_process(int *fd, char **argv, char **env);
int		parent_process(int *fd, char **argv, char **env);
char	*get_path(char *cmd, char **env);
int		main(int argc, char **argv, char **env);
int		ft_error(char **argv, int fd[2]);

#endif
