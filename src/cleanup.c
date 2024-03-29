/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 11:53:10 by sqiu              #+#    #+#             */
/*   Updated: 2023/03/29 19:13:56 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"
#include "../inc/cleanup.h"
#include "../inc/error.h"

/* This function closes remaining file descriptors and frees allocated 
memory space. */

void	cleanup(t_meta *meta)
{
	int	i;

	do_close(meta->fd_in);
	do_close(meta->fd_out);
	i = -1;
	while (meta->cmd_paths[++i])
		free(meta->cmd_paths[i]);
	free(meta->cmd_paths);
	free(meta->cmds);
}

/* This function performs the closing of a file and returns an error
if the closing failed. */

void	do_close(int fd)
{
	if (fd >= 0)
		if (close(fd) < 0)
			terminate(ERR_CLOSE);
}

/* This function closes all pipes which have been created. 
It executes the closing for all pipes created in previous
and including the current loop except if the the current
loop is the last loop. */

void	pipinator(t_meta *meta)
{
	int	j;

	j = -1;
	while (++j <= meta->i)
	{
		if (j < meta->cmd_num - 1)
			plug_pipes(meta, j);
	}
}

/* This function closes the pipe ends (= file descriptors) of the
specified pipe. */

void	plug_pipes(t_meta *meta, int i)
{
	do_close(meta->cmds[i].fd[0]);
	do_close(meta->cmds[i].fd[1]);
}
