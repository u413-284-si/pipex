/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 11:13:31 by sqiu              #+#    #+#             */
/*   Updated: 2023/03/16 17:34:14 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/error.h"
#include "../inc/pipex.h"


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

void	abort_mission(t_meta *meta)
{
	if (meta->here_doc)
		unlink(".heredoc_tmp");
	close(meta->fd_in);
	close(meta->fd_out);
	free(meta->cmds);
	terminate(ERR_PATH);
}
