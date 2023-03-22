/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 11:13:31 by sqiu              #+#    #+#             */
/*   Updated: 2023/03/22 12:19:08 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"
#include "../inc/error.h"

/* This function terminates the program and displays an error message 
according to the point in the program where the error happened. */

void	terminate(char *s)
{
	if (errno == 0)
		ft_putendl_fd(s, 2);
	else
		perror(s);
	exit(1);
}

/* This function verifies if the first argument is 'here_doc' and sets the
corresponding bool accordingly and returns the expected minimal number of
arguments to the program (including the program name itself). */

int	input_check(char *s, t_meta *meta)
{
	int	len;

	len = ft_strlen(s);
	if (len == 8 && ft_strncmp(s, "here_doc", len) == 0)
	{
		meta->here_doc = 1;
		return (6);
	}
	else
	{
		meta->here_doc = 0;
		return (5);
	}
}

/* This function closes all open file descriptors, frees allocated memory
space in the heap and unlinks any files at the current point. It then
gives out an error message and terminates the program. */

void	abort_mission(t_meta *meta, char *s)
{
	if (meta->here_doc)
		unlink(".tmp_heredoc");
	close(meta->fd_in);
	close(meta->fd_out);
	free(meta->cmds);
	terminate(s);
}

/* This function frees the cmd_paths and calls 'abort_mission' upon an
error. */

void	no_senor(t_meta *meta, char *s)
{
	int	i;

	i = -1;
	while (meta->cmd_paths[++i])
		free(meta->cmd_paths[i]);
	free(meta->cmd_paths);
	abort_mission(meta, s);
}

/* This function frees the arguments in the current command and 
calls 'no senor' upon an error. */

void	mamma_mia(t_meta *meta, char *s)
{
	int	i;

	i = -1;
	while (meta->cmds[meta->i].arg[++i])
		free(meta->cmds[meta->i].arg[i]);
	free(meta->cmds[meta->i].arg);
	no_senor(meta, s);
}
