/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 11:38:13 by sqiu              #+#    #+#             */
/*   Updated: 2023/03/29 18:08:38 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"
#include "../inc/commands.h"
#include "../inc/error.h"
#include "../inc/cleanup.h"
#include "../inc/children.h"
#include "../inc/utils.h"

/* This function executes the commands by creating

	* 1 pipe per two commands to be connected (no feedback loop)
		e.g. three commands require two pipes
		pipe 1: connecting command 1 and 2
		pipe 2: connecting command 2 and 3 
	* 1 child process per command 

Per each command itself and its arguments are retrieved and given to 
the child process. 

The children are created in parallel as in following children are born
even when the previous are still running. Due to the nature of pipes
suspending any process trying to read from a pipe until sth. is written
to it, the children implicitly wait for their predecessor to write
input to the pipe and then continue their execution. No explicit
wait call is therefore necessary in the parent process. */

void	execute_commands(t_meta *meta, char **argv, char **envp)
{
	int	i;

	meta->i = -1;
	while (++meta->i < meta->cmd_num)
	{
		if (meta->i < meta->cmd_num - 1)
			if (pipe(meta->cmds[meta->i].fd) < 0)
				no_senor(meta, ERR_PIPE);
		meta->cmds[meta->i].arg = \
			ft_split(argv[2 + meta->here_doc + meta->i], ' ');
		if (!meta->cmds[meta->i].arg)
			no_senor(meta, ERR_CMD);
		meta->cmds[meta->i].cmd = get_cmd(meta->cmds[meta->i].arg[0], \
			meta->cmd_paths);
		if (!meta->cmds[meta->i].cmd)
			perror("command not found");
		free(meta->cmds[meta->i].arg[0]);
		meta->cmds[meta->i].arg[0] = meta->cmds[meta->i].cmd;
		create_child(meta, envp);
		i = -1;
		while (meta->cmds[meta->i].arg[++i])
			free(meta->cmds[meta->i].arg[i]);
		free(meta->cmds[meta->i].arg);
	}
}

/* This function distinguishes between the position of the command needing
to be executed and creates the pertinent child. */

void	create_child(t_meta *meta, char **envp)
{
	if (meta->i == 0)
		raise_first(meta, envp);
	else if (meta->i == meta->cmd_num - 1)
		raise_last(meta, envp);
	else
		raise_middle(meta, envp);
}

/* This function creates a child by forking and calls the pertinent
function which is to be executed by the child. The parent does not wait
for the child to finish (flag WNOHANG set), but retrieves its pid when
its done. The parent closes the fd which are duplicated and used by the child.
*/

void	raise_first(t_meta *meta, char **envp)
{
	meta->cmds[meta->i].pid = fork();
	if (meta->cmds[meta->i].pid < 0)
		no_senor(meta, ERR_FORK);
	else if (meta->cmds[meta->i].pid == 0)
		firstborn(meta, envp);
	if (waitpid(meta->cmds[meta->i].pid, NULL, WNOHANG) < 0)
		mamma_mia(meta, ERR_FIRST);
	if (meta->fd_in > 0 && close(meta->fd_in) < 0)
		mamma_mia(meta, ERR_CLOSE);
	meta->fd_in = -1;
	if (close(meta->cmds[meta->i].fd[1]) < 0)
		mamma_mia(meta, ERR_CLOSE);
	meta->cmds[meta->i].fd[1] = -1;
}

/* This function creates a child by forking and calls the pertinent
function which is to be executed by the child. The parent waits
for the child to finish (no flags set) and retrieves its pid when
its done. This prohibits the parent to terminate before
the child has finished. 
The parent closes the fd which are duplicated and used by the child. 
*/

void	raise_last(t_meta *meta, char **envp)
{
	meta->cmds[meta->i].pid = fork();
	if (meta->cmds[meta->i].pid < 0)
		no_senor(meta, ERR_FORK);
	else if (meta->cmds[meta->i].pid == 0)
		lastborn(meta, envp);
	if (waitpid(meta->cmds[meta->i].pid, NULL, 0) < 0)
		mamma_mia(meta, ERR_LAST);
	if (close(meta->fd_out) < 0)
		mamma_mia(meta, ERR_CLOSE);
	meta->fd_out = -1;
	if (close(meta->cmds[meta->i - 1].fd[0]) < 0)
		mamma_mia(meta, ERR_CLOSE);
	meta->cmds[meta->i - 1].fd[0] = -1;
}

/* This function creates a child by forking and calls the pertinent
function which is to be executed by the child. The parent does not wait
for the child to finish (flag WNOHANG set), but retrieves its pid when
its done. The parent closes the fd which are duplicated and used by the child.
*/

void	raise_middle(t_meta *meta, char **envp)
{
	meta->cmds[meta->i].pid = fork();
	if (meta->cmds[meta->i].pid < 0)
		no_senor(meta, ERR_FORK);
	else if (meta->cmds[meta->i].pid == 0)
		middle_child(meta, envp);
	if (waitpid(meta->cmds[meta->i].pid, NULL, WNOHANG) < 0)
		mamma_mia(meta, ERR_MID);
	if (close(meta->cmds[meta->i - 1].fd[0]) < 0)
		mamma_mia(meta, ERR_CLOSE);
	meta->cmds[meta->i - 1].fd[0] = -1;
	if (close(meta->cmds[meta->i].fd[1]) < 0)
		mamma_mia(meta, ERR_CLOSE);
	meta->cmds[meta->i].fd[1] = -1;
}
