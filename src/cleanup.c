/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 11:53:10 by sqiu              #+#    #+#             */
/*   Updated: 2023/03/22 13:27:47 by sqiu             ###   ########.fr       */
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

	if (meta->here_doc)
		unlink(".tmp_heredoc");
	close(meta->fd_in);
	close(meta->fd_out);
	free(meta->cmds);
	i = -1;
	while (meta->cmd_paths[++i])
		free(meta->cmd_paths[i]);
	free(meta->cmd_paths);
}

/* This function unlinks the temporary heredoc file created and
terminates the program. */

void	unlink_heredoc(char *s)
{
	unlink(".tmp_heredoc");
	terminate(s);
}
