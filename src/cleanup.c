/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 11:53:10 by sqiu              #+#    #+#             */
/*   Updated: 2023/03/21 17:34:53 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"
#include "../inc/cleanup.h"

/* This function closes remaining file descriptors and frees allocated 
memory space. */

void	cleanup(t_meta *meta)
{
	int	i;

	if (meta->here_doc)
		unlink(".heredoc_tmp");
	close(meta->fd_in);
	close(meta->fd_out);
	free(meta->cmds);
	i = -1;
	while (meta->cmd_paths[++i])
		free(meta->cmd_paths[i]);
	free(meta->cmd_paths);
}
