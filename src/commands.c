/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 11:38:13 by sqiu              #+#    #+#             */
/*   Updated: 2023/03/20 17:10:41 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"
#include "../inc/commands.h"
#include "../inc/error.h"

/* This function executes the commands by creating

	* 1 pipe per two commands to be connected (no feedback loop)
		e.g. three commands require two pipes
		pipe 1: connecting command 1 and 2
		pipe 2: connecting command 2 and 3 
	* 1 child process per command 

Per each command itself and its arguments are retrieved and given to 
the child process. */

void	exec_cmd(t_meta *meta, char **argv, char **envp)
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
			mamma_mia(meta, ERR_CMDEX);
		free(meta->cmds[meta->i].arg[0]);
		meta->cmds[meta->i].arg[0] = meta->cmds[meta->i].cmd;
		create_child(meta, envp);
		i = -1;
		while (meta->cmds[meta->i].arg[++i])
			free(meta->cmds[meta->i].arg[i]);
		//free(meta->cmds[meta->i].arg);
		//free(meta->cmds[meta->i].cmd);
	}
}

/* This function prefixes the appropriate path in front of the command,
if that is not already the case. To this aim, it rotates through all
command paths and checks whether the combination with the command is
correct via 'access'. If so, the command including its path is returned.
In case of failure to find a working path to the command NULL is returned. */

char	*get_cmd(char *cmd, char **cmd_paths)
{
	char	*tmp;
	char	*rtrn;

	if (cmd[0] == '/')
		return (cmd);
	else
	{
		while (*cmd_paths)
		{
			tmp = ft_strjoin(*cmd_paths, "/");
			rtrn = ft_strjoin(tmp, cmd);
			free(tmp);
			if (access(rtrn, X_OK) == 0)
				return (rtrn);
			free(rtrn);
			cmd_paths++;
		}
		return (NULL);
	}
}

/* This function creates a child by forking and assigns the corresponding
file descriptors to stdin and stdout depending on the position of the
command in the chain. 
	First command: stdin = fd_in, stdout = write end of first pipe
	In between command: stdin = read end of previous pipe,
		stdout = write end of current pipe
	Last command: stdin = read end of previous pipe,
		stdout = fd_out
After assigning the fd, all fd in the child process are closed. 
The command is then called and executed with the new stdin & stdout. */

void	create_child(t_meta *meta, char **envp)
{
	meta->pid = fork();
	if (meta->pid < 0)
		no_senor(meta, ERR_FORK);
	else if (meta->pid == 0)
	{
		if (meta->i == 0)
			replace_fd(meta->fd_in, meta->cmds[meta->i].fd[1]);
		else if (meta->i == meta->cmd_num - 1)
			replace_fd(meta->cmds[meta->i - 1].fd[0], meta->fd_out);
		else
			replace_fd(meta->cmds[meta->i - 1].fd[0], \
				meta->cmds[meta->i].fd[1]);
		plug_pipes(meta);
		execve(meta->cmds[meta->i].cmd, meta->cmds[meta->i].arg, envp);
	}
	else
		wait(NULL);
}

/* This function replaces the standard file descriptors

* fd 0 (for system stdinput) with input_fd
* fd 1 (for system stdoutput) with output_fd

allowing data to be read and written to different files. */

void	replace_fd(int input_fd, int output_fd)
{
	dup2(input_fd, 0);
	dup2(output_fd, 1);
}

/* This function closes all pipe ends (= file descriptors) of the
created pipes. */

void	plug_pipes(t_meta *meta)
{
	int	i;

	i = -1;
	while (++i < meta->cmd_num - 1)
	{
		close(meta->cmds[i].fd[0]);
		close(meta->cmds[i].fd[1]);
	}
}