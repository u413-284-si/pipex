/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:21:58 by sqiu              #+#    #+#             */
/*   Updated: 2023/03/29 19:25:49 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"
#include "../inc/children.h"
#include "../inc/error.h"
#include "../inc/cleanup.h"
#include "../inc/utils.h"

/* This is the first command of the command chain. 

This function closes all unrequired file descriptors (all fd except
the two fd which are to replace stdin/stdout) and assigns the corresponding
file descriptors to stdin and stdout depending on the position of the
command in the chain.

	First command: stdin = fd_in, stdout = write end of first pipe

Afterwards these are closed as well and the command is being executed. */

void	firstborn(t_meta *meta, char **envp)
{
	do_close(meta->fd_out);
	do_close(meta->cmds[meta->i].fd[0]);
	replace_fd(meta->fd_in, meta->cmds[meta->i].fd[1]);
	do_close(meta->fd_in);
	do_close(meta->cmds[meta->i].fd[1]);
	if (execve(meta->cmds[meta->i].cmd, meta->cmds[meta->i].arg, envp) < 0)
	{
		pipinator(meta);
		mamma_mia(meta, ERR_FIRST);
	}
}

/* This is the last command of the command chain. 

This function closes all previous pipes except for the last pipe
connecting the last command to its predecessor. The write end of 
the last pipe is being closed. It assigns the corresponding
file descriptors to stdin and stdout depending on the position of the
command in the chain. 

	Last command: stdin = read end of previous pipe, stdout = fd_out

Afterwards these are closed as well and the command is being executed. */

void	lastborn(t_meta *meta, char **envp)
{
	do_close(meta->fd_in);
	do_close(meta->cmds[meta->i - 1].fd[1]);
	replace_fd(meta->cmds[meta->i - 1].fd[0], meta->fd_out);
	do_close(meta->fd_out);
	do_close(meta->cmds[meta->i - 1].fd[0]);
	if (execve(meta->cmds[meta->i].cmd, meta->cmds[meta->i].arg, envp) < 0)
	{
		pipinator(meta);
		mamma_mia(meta, ERR_LAST);
	}
}
