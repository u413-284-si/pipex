/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:21:58 by sqiu              #+#    #+#             */
/*   Updated: 2023/03/23 17:53:15 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"
#include "../inc/children.h"
#include "../inc/error.h"
#include "../inc/cleanup.h"
#include "../inc/commands.h"

/* This function closes all unrequired file descriptors (all fd except
the two fd which are to replace stdin/stdout) previous to
the duplication of the aforementioned fds. Afterwards these are closed
as well and the command is being executed. 

In this case it is the first command of the command chain. */

void	firstborn(t_meta *meta, char **envp)
{
	do_close(meta->fd_out);
	do_close(meta->cmds[meta->i].fd[0]);
	replace_fd(meta->fd_in, meta->cmds[meta->i].fd[1]);
	do_close(meta->fd_in);
	do_close(meta->cmds[meta->i].fd[1]);
	execve(meta->cmds[meta->i].cmd, meta->cmds[meta->i].arg, envp);
	perror("Failed to execute firstborn.\n");
	exit(1);
}

/* This function closes all previous pipes except for the last pipe
connecting the last command to its predecessor. The write end of 
the last pipe is being closed, then the required fds are duplicated 
to stdin/stdout and finally the remaining fds are closed. The
command is being executed.

This is the last command of the command chain. */

void	lastborn(t_meta *meta, char **envp)
{
	int	j;

	do_close(meta->fd_in);
	j = -1;
	while (++j < meta->i - 1)
		plug_pipes(meta, j);
	do_close(meta->cmds[meta->i - 1].fd[1]);
	replace_fd(meta->cmds[meta->i - 1].fd[0], meta->fd_out);
	do_close(meta->fd_out);
	do_close(meta->cmds[meta->i - 1].fd[0]);
	perror(meta->cmds[meta->i].cmd);
	perror(meta->cmds[meta->i].arg[0]);
	perror(meta->cmds[meta->i].arg[1]);
	perror(meta->cmds[meta->i].arg[2]);
	if (execve(meta->cmds[meta->i].cmd, meta->cmds[meta->i].arg, envp) < 0)
		mamma_mia(meta, ERR_LAST);
}

/* This function closes all previous pipes except for the last pipe
connecting the command to its predecessor. The write end of 
the previous pipe is being closed as well as the read end of
the current pipe, then the required fds are duplicated 
to stdin/stdout and finally the remaining fds are closed. The
command is being executed. 

This is a command in between the first and last. */

void	middle_child(t_meta *meta, char **envp)
{
	int	j;

	do_close(meta->fd_in);
	do_close(meta->fd_out);
	j = -1;
	while (++j < meta->i - 1)
		plug_pipes(meta, j);
	do_close(meta->cmds[meta->i - 1].fd[1]);
	do_close(meta->cmds[meta->i].fd[0]);
	replace_fd(meta->cmds[meta->i - 1].fd[0], meta->cmds[meta->i].fd[1]);
	do_close(meta->cmds[meta->i - 1].fd[0]);
	do_close(meta->cmds[meta->i].fd[1]);
	execve(meta->cmds[meta->i].cmd, meta->cmds[meta->i].arg, envp);
	perror("Failed to execute command.\n");
	exit(1);
}
