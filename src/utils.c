/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 15:02:39 by sqiu              #+#    #+#             */
/*   Updated: 2023/03/29 18:30:51 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"
#include "../inc/utils.h"
#include "../inc/error.h"

/* This function searches for the PATH in the environment and returns
it. */

char	*get_path(char **envp)
{
	while (ft_strncmp(*envp, "PATH", 4))
		envp++;
	return (*envp + 5);
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
/* This function replaces the standard file descriptors

* fd 0 (for system stdinput) with input_fd
* fd 1 (for system stdoutput) with output_fd

allowing data to be read and written to different files.
The input and output fds are closed after transfering their
file description to stdin and stdout respectively. */

void	replace_fd(int input_fd, int output_fd)
{
	if (dup2(input_fd, 0) < 0)
		terminate(ERR_DUP);
	if (dup2(output_fd, 1) < 0)
		terminate(ERR_DUP);
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
		return (rtrn = ft_strdup(cmd));
	else
	{
		while (*cmd_paths)
		{
			tmp = ft_strjoin(*cmd_paths, "/");
			rtrn = ft_strjoin(tmp, cmd);
			free(tmp);
			if (access(rtrn, F_OK | X_OK) == 0)
				return (rtrn);
			free(rtrn);
			cmd_paths++;
		}
		return (NULL);
	}
}
